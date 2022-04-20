#include <iostream>
#include <cassert>

//    Дан массив неотрицательных целых 64-разрядных чисел. Количество чисел не больше 10^6.
//    Отсортировать массив методом MSD по битам (бинарный QuickSort).


#define MAX_COUNT_ARRAY 1000000

bool get_bit(u_int64_t number, size_t bit) {
    return ((number >> bit) & 1);
}


u_int64_t *input_array(size_t max_count, size_t &count) {
    std::cin >> count;

    assert(count <= max_count);

    u_int64_t *res = new u_int64_t [count];

    for (size_t i = 0; i < count; ++i) {
        std::cin >> res[i];
    }

    return res;
}


void binary_MSD(u_int64_t *arr, size_t begin, size_t end, size_t k = 10) {
    assert(arr != nullptr);

    if (end - begin == 1) {
        return;
    }

    if (!k) {
        return;
    }

    size_t i = begin;
    size_t j = end;
    std::cout << i << " " << j << " " << std::endl;
    while (true) {
        while (i < end) {
            if (!((arr[i] >> k) & 1)) {
                ++i;
            } else {
                break;
            }
        }

        if (i == end) {
            break;
        }


        while (j > begin) {
            if (((arr[j] >> k) & 1)) {
                --j;
            } else {
                break;
            }
        }

        if (j == begin) {
            break;
        }

        std::swap(arr[i], arr[j]);
        ++i;
        --j;

        if (i == j - 1) {
            break;
        }

    }

    std::cout << begin  << " " << i << " " << j << " " << end << std::endl;

    if (i - begin > 1) {
        binary_MSD(arr, begin, i, k - 1);
    }

    if (end - j > 1) {
        //  binary_MSD(arr, j, end, k + 1);
    }
}


int main() {
    size_t length = 0;
    u_int64_t *array = input_array(MAX_COUNT_ARRAY, length);

    binary_MSD(array, 0, length - 1);

    for(size_t i = 0; i < length; ++i) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;

    delete[] array;

    return EXIT_SUCCESS;
}

/*
 *
 *  while (!((arr[i] >> k) & 1)) {
            ++i;
        }

        while ((arr[j] >> k) & 1) {
            --j;
        }

        if (i == j - 1) {
            break;
        }
 */
