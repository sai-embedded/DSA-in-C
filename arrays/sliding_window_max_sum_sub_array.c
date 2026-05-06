// “Instead of recomputing each subarray sum, I maintain a running sum and update it 
// by removing the outgoing element and adding the incoming element.”
int maxSumSubarray(int *arr, int n, int k)
{
    int current_sum = 0;

    // Step 1: first window
    for (int i = 0; i < k; i++)
    {
        current_sum += arr[i];
    }

    int max_sum = current_sum;

    // Step 2: slide window
    for (int i = k; i < n; i++)
    {
        current_sum = current_sum - arr[i - k] + arr[i];

        if (current_sum > max_sum)
        {
            max_sum = current_sum;
        }
    }

    return max_sum;
}