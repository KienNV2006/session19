#include <stdio.h>
#include <string.h>

struct SinhVien{
	int id;
	char name[50];
	int age;
	char phoneNumber[20];
};

void printSinhVien(SinhVien sv[], int size){
	printf("Danh sach sinh vien\n");
	for(int i=0; i<size; i++){
		printf("ID %d\n Ho va ten: %s\n Tuoi: %d\n So dien thoai: %s\n\n", sv[i].id, sv[i].name, sv[i].age, sv[i].phoneNumber);
	}
}

void sortSinhVienByName(SinhVien sv[], int size){
	struct SinhVien temp;
	for(int i=0; i<size-1; i++){
		for(int j=i+1; j<size; j++){
			if(strcmp(sv[i].name,sv[j].name)>0){
				temp=sv[i];
				sv[i]=sv[j];
				sv[j]=temp;
			}
		}
	}
}

int main(){
	struct SinhVien sv[5]={
		{1, "Nguyen Van B",18,"0123456789"},
		{2, "Nguyen Van C",19,"0123456788"},
		{3, "Nguyen Van A",20,"0123456787"},
		{4, "Nguyen Van E",21,"0123456786"},
		{5, "Nguyen Van D",22,"0123456785"}
	};
	int size=5;
	printSinhVien(sv, size);
	sortSinhVienByName(sv,size);
	printf("Danh sach sau khi da sap xep la:\n");
	printSinhVien(sv, size);
	return 0;
}