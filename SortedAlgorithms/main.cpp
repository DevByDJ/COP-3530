#include <iostrean>
#include <algorithm>

#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

const int ARRAY_SIZE = 6;

void printArray(std::string label, int array[], int size, long long time = 0, bool time_only = false);

void selectionSort(int arr[], int n);

int main() {
    
    int input[ARRAY_SIZE] = {2, 7, 4, 1, 5, 3};
    int sort[ARRAY_SIZE];

    printArray("Unsorted", input, ARRAY_SIZE);

    std::copy(std::begin(input), std::end(input), std::begin(sort));

    auto start_time = Clock::now();

    selectionSort(sort, ARRAY_SIZE);

    auto end_time = Clock::now();

    printArray("Selection sort", sort, ARRAY_SIZE,
                std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count());

    return 0;

}

void printArray(std::string label, int array[], int size, long long time, bool time_only) {
    if(!time_only) {
        std::printf("%s", label.c_str());
        for(int i = 0; i < size; i++)
        {
            if (i > 0)
                std::printf(",");
            std::printf("%d", array[i]);
        }
        std::printf("\n");
    }

    std::printf("Took: %llu ns\n", time);
    std::cout.flush();
}

void selectionSort(int arr[], int n) {
    
}

