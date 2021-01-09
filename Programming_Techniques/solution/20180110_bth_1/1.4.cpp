int counteven(int* arr, int size)
{
    int count = 0;
    for(int i=0; i<size; i++)
    {
        if(arr[i]%2==0)
        {
            count+=1;
        }
    }
    return count;    
}