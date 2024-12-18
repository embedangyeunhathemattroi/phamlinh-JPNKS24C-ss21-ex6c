#include <stdio.h>
#include <string.h>

struct SinhVien {
    int IDmoi;             
    char name[50];         
    int age;              
    char phone[50];        
};

typedef struct SinhVien SinhVien;


void themSinhVien(SinhVien students[], int *size) {
    if (*size >= 5) {
        printf("Danh sach sinh vien da day, khong the them sinh vien moi!\n");
        return;
    
    int n;
    SinhVien newStudents[100]; 
    printf("Nhap so luong sinh vien can them: ");
    scanf("%d", &n);
    getchar(); 
    nhapDS(newStudents, n); 
    xuatDS(newStudents, n);

    }
    


    students[*size].IDmoi = *size + 1;


    printf("Nhap ten sinh vien: ");
    fgets(students[*size].name, sizeof(students[*size].name), stdin);
    students[*size].name[strcspn(students[*size].name, "\n")] = '\0'; 

  
    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &students[*size].age);
    getchar(); 

    printf("Nhap so dien thoai sinh vien: ");
    fgets(students[*size].phone, sizeof(students[*size].phone), stdin);
    students[*size].phone[strcspn(students[*size].phone, "\n")] = '\0'; 


    (*size)++;
}


void inDanhSachSinhVien(SinhVien students[], int size) {
    printf("\nDanh sach sinh vien:\n");
    printf("%-5s %-20s %-5s %-15s\n", "ID", "Ten", "Tuoi", "So Dien Thoai");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%-5d %-20s %-5d %-15s\n", students[i].IDmoi, students[i].name, students[i].age, students[i].phone);
    }
}


void nhapDS(SinhVien a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i].IDmoi = i + 1; 
        printf("Nhap thong tin sinh vien %d:\n", i + 1);
        
        printf("Nhap ten sinh vien: ");
        fgets(a[i].name, sizeof(a[i].name), stdin);
        a[i].name[strcspn(a[i].name, "\n")] = '\0'; 

        printf("Nhap tuoi sinh vien: ");
        scanf("%d", &a[i].age);
        getchar();  

        printf("Nhap so dien thoai sinh vien: ");
        fgets(a[i].phone, sizeof(a[i].phone), stdin);
        a[i].phone[strcspn(a[i].phone, "\n")] = '\0'; 
    }
}

void xuatDS(SinhVien a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, So dien thoai: %s\n", a[i].IDmoi, a[i].name, a[i].age, a[i].phone);
    }
}

int main() {
    SinhVien students[10] = {
        {1, "Linh Ngoc Pham", 18, "0346333182"},
        {2, "Dang Hai Chau", 16, "09385109083"},
        {3, "Chu Huyen Anh", 17, "0974006455"},
        {4, "Cao Uyen Chi", 19, "09633222"},
        {5, "Chu Tue Anh", 24, "097888888"}
    };

    int size = 5;
    inDanhSachSinhVien(students, size);

    printf("\nHay them sinh vien moi:\n");
    themSinhVien(students, &size);

    printf("\nTong hop danh sach sinh vien sau khi them:\n");
    inDanhSachSinhVien(students, size);

  

    return 0;
}

