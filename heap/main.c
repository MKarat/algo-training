// Программа реализующая алгоритм пирамидальной сортировки массива,
// основанного на индексах

#include <stdio.h>
#include "../common/array_io.h" 

// Функция обмена значений под двумя указателями
void Swap(double* ptr1, double* ptr2){
    double buf = *ptr1;
    *ptr1 = *ptr2; 
    *ptr2 = buf;
}


int main (void){

    // Cчитывание массива из файла input.txt
    double* array = NULL;
    int array_size = FillArray("input.txt", &array);
    PrintArray("Initial array:", array, array_size);
    
    // Построение пирамиды
    double heap[array_size];
    heap[0] = array[0];

    // строим пирамиду снизу
    for (int i = 1; i <= array_size; ++i){
               
        // добавляем очередной элемент массива на дно пирамиды
        heap[i] = array[i];

        // поднимаем добавленный элемент до требуемого уровня пирамиды
        int j = i;
        
        while(j > 0){                               // условие достижения корня            
            
            if(heap[(j-1)/2] < heap[j])             // условие подъема
                Swap(&heap[(j-1)/2], &heap[j]);     // перестановка с родителем
            else break;                             // если подъем не нужен, то
                                                    // цикл while завершается

            j = (j-1)/2;                            // переход на уровень выше
        }
    }

    free(array);        // исходный массив уже не нужен, освобождаем память

    PrintArray("Initial heap:", heap, array_size);

    // Извлечём из пирамиды максимальное значение    
    int heap_size = array_size;

    double max = heap[0];       // максимальное значение - вершина пирамиды
    heap[0] = heap[heap_size-1];  // поставим элемент со дна на вершину
    --heap_size;                // удалим последний элемент, уменьшив размер
                                // пирамиды на единицу

    // Восстановим пирамиду просеиванием вниз корневого элемента 
    
    int i = 0;          // индекс текущего элемента, начинаем с вершины
    int right = 2;      // индекс правого потомка    

    while(right < heap_size){               // условие достижения дна пирамиды
        
        PrintArray("Curent heap:", heap, heap_size);
        
        int local_max_index = i;    // индекс максимального элемента в семье из
                                    // трёх верших
        int left = 2*i+1;           // индекс левого потомка
        right = 2*i+2; 

        // найдём максимальный элемент в семье из трёх вершин
        if (heap[i] < heap[left] && left < heap_size)
            local_max_index = left;
        if (heap[left] < heap[right] && right < heap_size )
            local_max_index = right;    

        // если родительский элемент не является максимальным в семействе, то 
        // необходима перестановка с максимальным элементом
        if (local_max_index != i)
            Swap(&heap[i], &heap[local_max_index]);
        else break;      // если перестановка не требуется то пирмаида
                         // восстановлена и цикл завершается
        
        i = local_max_index; // спуск на уровень ниже в направлении, в котором
                             // была произведена замена
    }
    
    PrintArray("Final heap:", heap, heap_size);

    return 0;
}