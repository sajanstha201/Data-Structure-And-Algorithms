#include<stdio.h>
#include<string.h>
    struct car{
        int modelYear,exShowRoomPrice;
        char carName[50],brandName[50],variant[50];
    };
    struct car myCar[10];
int k=0;
void linearSearch(char *brandName){
    int i;
    printf("The details of car with %s brand name are: ",brandName);
    for(i=0;i<10;i++)
        if(strcmp(brandName,myCar[i].brandName)==0){
            printf("Model Year: %d\n Car Name: %s \n Brand Name:%s\n",myCar[i].modelYear,myCar[i].carName,myCar[i].brandName);
            printf(" Variant:%s\nEx-showroom Price: %d\n\n",myCar[i].variant,myCar[i].exShowRoomPrice);
        }
}
void bubblesort(){
    int i,j;
    struct car temp;
    for(i=0;i<k;i++){
        for(j=0;j<k-i-1;j++){
            if(strcmp(myCar[j].carName,myCar[j+1].carName)>0){
                temp=myCar[j];
                myCar[j]=myCar[j+1];
                myCar[j+1]=temp;
            }
        }
    }
    for(i=0;i<k;i++)
        printf("%s ",myCar[i].carName);
}
void binarySearch(char carName[]){
    int i=0,j=k-1,mid;
    while(1){
        mid=(i+j)/2;
        if(i>j){
            printf("The car is not found\n");
            break;
        }
        if(strcmp(myCar[mid].carName,carName)==0){
            printf("Model Year: %d\n Car Name: %s \n Brand Name:%s\n",myCar[mid].modelYear,myCar[mid].carName,myCar[mid].brandName);
            printf(" Variant:%s\nEx-showroom Price: %d\n\n",myCar[mid].variant,myCar[mid].exShowRoomPrice);
            break;
        }
        else if(strcmp(myCar[mid].carName,carName)<0){
            i=mid+1;
        }
        else{
            j=mid-1;
        }
    }
}
int main(){
    printf("1.Add car details \n2.searching by brand Name\n3. searching by car Name \n4.sorting \n5.exit\n");
    char brandName[50],carName[50];
    while(1){
        int choice;
        printf("Enter a choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                    printf("For %d Car:\n",k+1);
                    printf("Model Year: ");
                    scanf("%d",&myCar[k].modelYear);
                    printf("Car Name: ");
                    scanf("%s",myCar[k].carName);
                    printf("Brand Name: ");
                    scanf("%s",myCar[k].brandName);
                    printf("Variant: ");
                    scanf("%s",myCar[k].variant);
                    printf("Ex-ShowRoom Price: ");
                    scanf("%d",&myCar[k].exShowRoomPrice);
                    k++;
                break;
            case 2:
                printf("Enter brand Name for searching: ");
                scanf("%s",brandName);
                linearSearch(brandName);
                break;
            case 3:
                printf("Enter car Name for searching: ");
                scanf("%s",carName);
                binarySearch(carName);
                break;
            case 4:
                bubblesort();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");

        }
    }

}