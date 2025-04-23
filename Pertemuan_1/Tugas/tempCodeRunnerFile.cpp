void selectionSort(int arr[], int n)
{
    int i, j, maxIndex, temp;
    for (i = 0; i < n - 1; i++)
    {
        maxIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[maxIndex])
            {
                maxIndex = j;
            }   
        }

        temp = arr[maxIndex];
        arr[maxIndex] = arr[i];
        arr[i] = temp;
        cout << "Iterasi ke- " << i + 1 << ": ";

        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << ' ';\
        }
        
        cout << endl;
    }
}