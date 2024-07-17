#include <stdio.h>
int main()
{
    int incoming, outgoing, buck_size, n, store = 0;
    printf("Enter bucket size, outgoing rate and no of inputs: ");
    scanf("%d %d %d", &buck_size, &outgoing, &n);

    while (n != 0)
    {
        printf("Enter the incoming packet size : ");
        scanf("%d", &incoming);
        printf("Incoming packet size is: %d\n", incoming);
        if (incoming <= (buck_size - store))
        {
            store += incoming;
            printf("%d packets are stored in the Bucket size of %d\n", store, buck_size);
        }
        else
        {
            printf("%d packets are dropped\n", incoming - (buck_size - store));
            store = buck_size;
        }
        store = store - outgoing;
        printf("After outgoing %d packets are left out of %d in bucket\n", store, buck_size);
        n--;
    }
    return 0;
}

/*
300 50 3
200
200
200
*/