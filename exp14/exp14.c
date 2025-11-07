#include <stdio.h>

int main() {
    int n, pageSize, i;

    // Step 1: Input number of pages and page size
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter page size (in bytes): ");
    scanf("%d", &pageSize);

    int frameNumber[n]; // Page table

    // Step 2: Input frame numbers for each page
    printf("\nEnter the frame number where each page is stored:\n");
    for(i = 0; i < n; i++) {
        printf("Page %d --> Frame: ", i);
        scanf("%d", &frameNumber[i]);
    }

    // Step 3: Translate a logical address to a physical address
    int logicalAddress;
    printf("\nEnter a logical address (in bytes): ");
    scanf("%d", &logicalAddress);

    // Compute page number and offset
    int pageNumber = logicalAddress / pageSize;
    int offset = logicalAddress % pageSize;

    // Step 4: Get physical address using the page table
    if(pageNumber >= n) {
        printf("\nInvalid logical address! Page number out of range.\n");
    } else {
        int frame = frameNumber[pageNumber];
        int physicalAddress = frame * pageSize + offset;

        printf("\n--- Address Translation ---\n");
        printf("Logical Address: %d\n", logicalAddress);
        printf("Page Number: %d\n", pageNumber);
        printf("Offset: %d\n", offset);
        printf("Frame Number: %d\n", frame);
        printf("Physical Address: %d\n", physicalAddress);
    }

    return 0;
}