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

int deleteById(int id, SinhVien sv[], int *size){
	for(int i=0; i<*size; i++){
		if(sv[i].id==id){
			for(int j=i; j<*size-1; j++){
				sv[j]=sv[j+1];
			}
			(*size--);
			return 1;
		}
	}
	return 0;
}

int main(){
	struct SinhVien sv[5]={
		{1, "Nguyen Van A",18,"0123456789"},
		{2, "Nguyen Van B",19,"0123456788"},
		{3, "Nguyen Van C",20,"0123456787"},
		{4, "Nguyen Van D",21,"0123456786"},
		{5, "Nguyen Van E",22,"0123456785"}
	};
	int size=5;
	printSinhVien(sv, size);
	int idToDelete;
	printf("Moi ban nhap vao ID sinh vien can xoa: ");
	scanf("%d", &idToDelete);
	int check=deleteById(idToDelete, sv, &size);
	if(check=1){
		printf("Xoa sinh vien thanh cong\n");
	}else{
		printf("Sinh vien khong ton tai!!!\n");
	}
	printSinhVien(sv, size);
	return 0;
}