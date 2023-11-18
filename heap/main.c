// Программа реализующая алгоритм пирамидальной сортировки массива,
// основанного на индексах

#include <stdio.h>
#include "../common/array_io.h" 

// Функция обмена значений под двумя указателями
void Swap(double* ptr1, double* ptr2);

// Функция построения пирамиды
void BuildHeap(double* array, unsigned int array_size, double* heap);

// Функция извлечения максимального значения из пирамиды
double ExtractMax(double* heap, unsigned int* heap_size);

// Функция пирамидальной сортировки
void HeapSort(double* array, unsigned int array_size);


int main (void){

    // Cчитывание массива из файла input.txt
    double* array = NULL;
    const unsigned int array_size = FillArray("input.txt", &array);
    
    PrintArray("Initial array:", array, array_size);
    HeapSort(array, array_size);  
    PrintArray("Sorted array:", array, array_size);

    free(array); // освобождаем память

    return 0;
}


// Функция обмена значений под двумя указателями
void Swap(double* ptr1, double* ptr2){
    double buf = *ptr1;
    *ptr1 = *ptr2; 
    *ptr2 = buf;
}

// Функция построения пирамиды
void BuildHeap(double* array, unsigned int array_size, double* heap){
    
    heap[0] = array[0];

    // строим пирамиду снизу
    for (unsigned int i = 1; i <= array_size; ++i){
               
        // добавляем очередной элемент массива на дно пирамиды
        heap[i] = array[i];

        // поднимаем добавленный элемент до требуемого уровня пирамиды
        unsigned int j = i;
        
        while(j > 0){                               // условие достижения корня            
            
            if(heap[(j-1)/2] < heap[j])             // условие подъема
                Swap(&heap[(j-1)/2], &heap[j]);     // перестановка с родителем
            else break;                             // если подъем не нужен, то
                                                    // цикл while завершается

            j = (j-1)/2;                            // переход на уровень выше
        }
    }
}

// Функция извлечения максимального значения из пирамиды
double ExtractMax(double* heap, unsigned int* heap_size){
    
    double max = heap[0];           // максимальное значение - вершина пирамиды
    heap[0] = heap[*heap_size-1];   // поставим элемент со дна на вершину
    --(*heap_size);                 // удалим последний элемент, уменьшив размер
                                    // пирамиды на единицу

    // Восстановим пирамиду просеиванием вниз корневого элемента 
    
    unsigned int i = 0;          // индекс текущего элемента, начинаем с вершины
    
    while(i < *heap_size){               // условие достижения дна пирамиды
        
        //PrintArray("Curent heap:", heap, *heap_size);
        
        unsigned int local_max_index = i;   // индекс максимального элемента 
                                            // в семье из трёх верших
        unsigned int left = 2*i+1;          // индекс левого потомка
        unsigned int right = 2*i+2;         // индекс правого потомка    

        // найдём максимальный элемент в семье из трёх вершин
        if (heap[i] < heap[left] && left < *heap_size)
            local_max_index = left;
        if (heap[left] < heap[right] && right < *heap_size )
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

    return max;
}

// Функция пирамидальной сортировки
void HeapSort(double* array, unsigned int array_size){
    
    // Построение пирамиды
    double heap[array_size];
    BuildHeap(array, array_size, heap);
    
    unsigned int heap_size = array_size;
    
    for(unsigned int i = 0; i < array_size; ++i){
        double max = ExtractMax(heap, &heap_size);
        array[i] = max;
    }
}