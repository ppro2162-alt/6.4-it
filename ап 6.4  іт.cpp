#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// ---------- Заповнення масиву випадковими числами ----------
void FillArray(int* a, const int size, const int low, const int high);
template <typename T>
void FillArray(T* a, const int size, const int low, const int high);

// ---------- Виведення масиву ----------
void PrintArray(const int* a, const int size);
template <typename T>
void PrintArray(const T* a, const int size);

// ---------- Пошук індексу максимального елемента ----------
int FindMaxIndex(const int* a, const int size);
template <typename T>
int FindMaxIndex(const T* a, const int size);

// ---------- Пошук індексу першого нуля, починаючи зі start ----------
int FindZeroIndex(const int* a, const int size, const int start);
template <typename T>
int FindZeroIndex(const T* a, const int size, const int start);

// ---------- Добуток елементів a[from] ... a[to - 1] ----------
int ProductBetween(const int* a, const int from, const int to);
template <typename T>
T ProductBetween(const T* a, const int from, const int to);

// ---------- Добуток між першим і другим нулями ----------
bool ProductBetweenZeros(const int* a, const int size, int& product);
template <typename T>
bool ProductBetweenZeros(const T* a, const int size, T& product);

// ---------- Копіювання кожного другого елемента ----------
void CopyEveryOther(const int* src, const int size, const int start, int* dst, const int dstStart);
template <typename T>
void CopyEveryOther(const T* src, const int size, const int start, T* dst, const int dstStart);

// ---------- Копіювання масиву ----------
void CopyArray(const int* src, int* dst, const int size);
template <typename T>
void CopyArray(const T* src, T* dst, const int size);

// ---------- Перестановка: спочатку непарні позиції, потім парні ----------
void RearrangeOddEven(int* a, const int size);
template <typename T>
void RearrangeOddEven(T* a, const int size);

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    if (n <= 0)
    {
        cout << "n must be positive" << endl;
        return 1;
    }
    srand(static_cast<unsigned>(time(0)));

    // ===== Звичайні функції (int) =====
    cout << endl << "--- int (plain functions) ---" << endl;
    int* a = new int[n];
    FillArray(a, n, -3, 3);
    cout << "Array:  ";
    PrintArray(a, n);
    cout << endl;

    cout << "Max element number: " << FindMaxIndex(a, n) + 1 << endl;

    int p;
    if (ProductBetweenZeros(a, n, p))
        cout << "Product between first and second zero: " << p << endl;
    else
        cout << "No product: need two zeros with elements between them" << endl;

    RearrangeOddEven(a, n);
    cout << "Result: ";
    PrintArray(a, n);
    cout << endl;
    delete[] a;

    // ===== Шаблони, T = int =====
    cout << endl << "--- template, T = int ---" << endl;
    int* a2 = new int[n];
    FillArray<int>(a2, n, -3, 3);
    cout << "Array:  ";
    PrintArray<int>(a2, n);
    cout << endl;

    cout << "Max element number: " << FindMaxIndex<int>(a2, n) + 1 << endl;

    int p2;
    if (ProductBetweenZeros<int>(a2, n, p2))
        cout << "Product between first and second zero: " << p2 << endl;
    else
        cout << "No product: need two zeros with elements between them" << endl;

    RearrangeOddEven<int>(a2, n);
    cout << "Result: ";
    PrintArray<int>(a2, n);
    cout << endl;
    delete[] a2;

    // ===== Шаблони, T = double =====
    cout << endl << "--- template, T = double ---" << endl;
    double* b = new double[n];
    FillArray<double>(b, n, -3, 3);
    cout << "Array:  ";
    PrintArray<double>(b, n);
    cout << endl;

    cout << "Max element number: " << FindMaxIndex<double>(b, n) + 1 << endl;

    double p3;
    if (ProductBetweenZeros<double>(b, n, p3))
        cout << "Product between first and second zero: " << p3 << endl;
    else
        cout << "No product: need two zeros with elements between them" << endl;

    RearrangeOddEven<double>(b, n);
    cout << "Result: ";
    PrintArray<double>(b, n);
    cout << endl;
    delete[] b;

    return 0;
}

// ================= FillArray =================
void FillArray(int* a, const int size, const int low, const int high)
{
    for (int i = 0; i < size; i++)
        a[i] = low + rand() % (high - low + 1);
}

template <typename T>
void FillArray(T* a, const int size, const int low, const int high)
{
    for (int i = 0; i < size; i++)
        a[i] = static_cast<T>(low + rand() % (high - low + 1));
}

// ================= PrintArray =================
void PrintArray(const int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(5) << a[i];
}

template <typename T>
void PrintArray(const T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(5) << a[i];
}

// ================= FindMaxIndex =================
int FindMaxIndex(const int* a, const int size)
{
    int maxIndex = 0;
    for (int i = 1; i < size; i++)
        if (a[i] > a[maxIndex])
            maxIndex = i;
    return maxIndex;
}

template <typename T>
int FindMaxIndex(const T* a, const int size)
{
    int maxIndex = 0;
    for (int i = 1; i < size; i++)
        if (a[i] > a[maxIndex])
            maxIndex = i;
    return maxIndex;
}

// ================= FindZeroIndex =================
int FindZeroIndex(const int* a, const int size, const int start)
{
    for (int i = start; i < size; i++)
        if (a[i] == 0)
            return i;
    return -1;
}

template <typename T>
int FindZeroIndex(const T* a, const int size, const int start)
{
    for (int i = start; i < size; i++)
        if (a[i] == T())
            return i;
    return -1;
}

// ================= ProductBetween =================
int ProductBetween(const int* a, const int from, const int to)
{
    int p = 1;
    for (int i = from; i < to; i++)
        p *= a[i];
    return p;
}

template <typename T>
T ProductBetween(const T* a, const int from, const int to)
{
    T p = T(1);
    for (int i = from; i < to; i++)
        p *= a[i];
    return p;
}

// ================= ProductBetweenZeros =================
bool ProductBetweenZeros(const int* a, const int size, int& product)
{
    int first = FindZeroIndex(a, size, 0);
    if (first == -1)
        return false;
    int second = FindZeroIndex(a, size, first + 1);
    if (second == -1 || second == first + 1)
        return false;
    product = ProductBetween(a, first + 1, second);
    return true;
}

template <typename T>
bool ProductBetweenZeros(const T* a, const int size, T& product)
{
    int first = FindZeroIndex<T>(a, size, 0);
    if (first == -1)
        return false;
    int second = FindZeroIndex<T>(a, size, first + 1);
    if (second == -1 || second == first + 1)
        return false;
    product = ProductBetween<T>(a, first + 1, second);
    return true;
}

// ================= CopyEveryOther =================
void CopyEveryOther(const int* src, const int size, const int start, int* dst, const int dstStart)
{
    int j = dstStart;
    for (int i = start; i < size; i += 2)
        dst[j++] = src[i];
}

template <typename T>
void CopyEveryOther(const T* src, const int size, const int start, T* dst, const int dstStart)
{
    int j = dstStart;
    for (int i = start; i < size; i += 2)
        dst[j++] = src[i];
}

// ================= CopyArray =================
void CopyArray(const int* src, int* dst, const int size)
{
    for (int i = 0; i < size; i++)
        dst[i] = src[i];
}

template <typename T>
void CopyArray(const T* src, T* dst, const int size)
{
    for (int i = 0; i < size; i++)
        dst[i] = src[i];
}

// ================= RearrangeOddEven =================
void RearrangeOddEven(int* a, const int size)
{
    int* tmp = new int[size];
    CopyEveryOther(a, size, 0, tmp, 0);                // позиції 1, 3, 5, ...
    CopyEveryOther(a, size, 1, tmp, (size + 1) / 2);   // позиції 2, 4, 6, ...
    CopyArray(tmp, a, size);
    delete[] tmp;
}

template <typename T>
void RearrangeOddEven(T* a, const int size)
{
    T* tmp = new T[size];
    CopyEveryOther<T>(a, size, 0, tmp, 0);
    CopyEveryOther<T>(a, size, 1, tmp, (size + 1) / 2);
    CopyArray<T>(tmp, a, size);
    delete[] tmp;
}