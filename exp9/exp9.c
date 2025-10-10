#include <stdio.h>

void main(){
    int buffersize,produce,consume;
    int items = 0;
    int in = 0;
    int out = 0;
    int ch;
    printf("Enter Buffer Size:");
    scanf("%d",&buffersize);
    int buffer[buffersize];

    do{
        printf("\nProducer Consumer Problem\n");
        printf("1.Produce\n2.Consume\n3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                if(items==buffersize) printf("Buffer Full!");
                else{
                    printf("Enter item value:");
                    scanf("%d",&produce);
                    buffer[in] = produce;
                    in = (in+1) % buffersize;
                    items++;   
                }
                break;
            case 2:
                if(items == 0) printf("Buffer empty!");
                else{
                    consume = buffer[out];
                    printf("Consumed value is:%d",consume);
                    out = (out+1)%buffersize;
                    items--;
                }
                break;
        }
    }
    while(ch != 3);
}