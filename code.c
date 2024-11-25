#include <stdio.h>
#include <string.h>

int i=0;

struct data{
    char nama[100], huruf[3];
    int eval1,eval2,eval3,nrp,uas,max,min;
    float rata_rata;
} mahasiswa[120];

struct maximal{
    float nilai;
    char nama[100];
};

struct minimal{
    float nilai;
    char nama[100];
};

struct rata{
    float nilai;
    struct minimal min;
    struct maximal max;
}rata_rata;

struct evaln1{
    struct minimal min;
    struct maximal max;
}eval1;

struct evaln2{
    struct minimal min;
    struct maximal max;
}eval2;

struct evaln3{
    struct minimal min;
    struct maximal max;
}eval3;

struct uasn{
    struct minimal min;
    struct maximal max;
}uas;

void menu(){
    int pilihan;
    puts("Silahkan pilih menu anda: ");
    puts("1. Menambahkan mahasiswa dan nilai");
    puts("2. Menampilkan Data Mahasiswa");
    puts("3. Selesai");
    printf("Masukkan pilihan anda: ");
    scanf("%d", &pilihan);

    switch(pilihan)
    {
        case 1:
        menambah();
        break;
        case 2:
        show();
        break;
        case 3:
        exit(1);
        default:
        printf("Input salah coba lagi\n\n");
        menu();
        break;
    }
}

void menambah(){
    char jawab;
    do {
        printf("Data Mahasiswa ke-%d\n", i+1);
        printf("NRP: ");
        scanf("%d", &mahasiswa[i].nrp);
        printf("Nama: ");
        scanf("%s", mahasiswa[i].nama);
        printf("Masukkan nilai\n");
        printf("Eval1 Eval2 Eval3 UAS: ");
        scanf(" %d %d %d %d", &mahasiswa[i].eval1, &mahasiswa[i].eval2, &mahasiswa[i].eval3, &mahasiswa[i].uas);

        //Mencari maks min dari setiap nilai
        int nilai[] = {mahasiswa[i].eval1, mahasiswa[i].eval2, mahasiswa[i].eval3, mahasiswa[i].uas};
        mahasiswa[i].max = nilai[0];
        mahasiswa[i].min = nilai[0];
        for (int j = 0; j < 4; j++)
        {
            if (mahasiswa[i].max < nilai[j]) mahasiswa[i].max = nilai[j];
            if (mahasiswa[i].min > nilai[j]) mahasiswa[i].min = nilai[j];
        }

        //Nilai rata rata mahasisswa
        mahasiswa[i].rata_rata = (float) (mahasiswa[i].eval1 + mahasiswa[i].eval2 + mahasiswa[i].eval3 + mahasiswa[i].uas) / 4.0;

        //cek huruf
        ceknilai();
        i++;

        printf("Mau menambah mahasiswa lagi? [Y/T]: ");
        scanf(" %c", &jawab);
        
    } while (jawab == 'y' || jawab == 'Y');
}

void show(){
    rata_rata.max.nilai = 0;
    rata_rata.min.nilai = 101;

    eval1.max.nilai = 0;
    eval1.min.nilai = 101;

    eval2.max.nilai = 0;
    eval2.min.nilai = 101;

    eval3.max.nilai = 0;
    eval3.min.nilai = 101;

    uas.max.nilai = 0;
    uas.min.nilai = 101;

    float jumlah = 0.0;
    printf("=======================================================================================\n");
    puts("No. \tNrp\tNama\tEval1\tEval2\tEval3\tUAS\tRata-Rata\tMaks\tMin\tHuruf");
    printf("=======================================================================================\n");
    for (int j = 0; j < i; j++)
    {
        jumlah += mahasiswa[j].rata_rata;
        cekdata(j);
        printf("%d\t%d\t%s\t%d\t%d\t%d\t%d\t%.2f\t\t%d\t%d\t%s\n", j+1, mahasiswa[j].nrp, mahasiswa[j].nama, mahasiswa[j].eval1, mahasiswa[j].eval2, mahasiswa[j].eval3, mahasiswa[j].uas, mahasiswa[j].rata_rata, mahasiswa[j].max, mahasiswa[j].min, mahasiswa[j].huruf);
    }
    puts("");

    rata_rata.nilai = jumlah / (float)i;

    printf("Nilai rata rata seluruh mahasiswa        : %.2f\n", rata_rata.nilai);
    printf("Nilai rata rata mahasiswa tertinggi      : %s dengan nilai %.2f\n", rata_rata.max.nama, rata_rata.max.nilai);
    printf("Nilai rata rata mahasiswa terendah       : %s dengan nilai %.2f\n", rata_rata.min.nama, rata_rata.min.nilai);
    printf("Nilai mahasiswa dengan eval1 tertinggi   : %s dengan nilai %.f\n", eval1.max.nama, eval1.max.nilai);
    printf("Nilai mahasiswa dengan eval1 terendah    : %s dengan nilai %.f\n", eval1.min.nama, eval1.min.nilai);
    printf("Nilai mahasiswa dengan eval2 tertinggi   : %s dengan nilai %.f\n", eval2.max.nama, eval2.max.nilai);
    printf("Nilai mahasiswa dengan eval2 terendah    : %s dengan nilai %.f\n", eval2.min.nama, eval2.min.nilai);
    printf("Nilai mahasiswa dengan eval3 tertinggi   : %s dengan nilai %.f\n", eval3.max.nama, eval3.max.nilai);
    printf("Nilai mahasiswa dengan eval3 terendah    : %s dengan nilai %.f\n", eval3.min.nama, eval3.min.nilai);
    printf("Nilai mahasiswa dengan uas tertinggi     : %s dengan nilai %.f\n", uas.max.nama, uas.max.nilai);
    printf("Nilai mahasiswa dengan uas terdendah     : %s dengan nilai %.f\n", uas.min.nama, uas.min.nilai);
};

void cekdata(int j){
    if (rata_rata.max.nilai < mahasiswa[j].rata_rata)
    {
        rata_rata.max.nilai = mahasiswa[j].rata_rata;
        strcpy(rata_rata.max.nama, mahasiswa[j].nama);
    }
    if (rata_rata.min.nilai > mahasiswa[j].rata_rata)
    {
        rata_rata.min.nilai = mahasiswa[j].rata_rata;
        strcpy(rata_rata.min.nama, mahasiswa[j].nama);
    }
    if (eval1.max.nilai < mahasiswa[j].eval1)
    {
        eval1.max.nilai = mahasiswa[j].eval1;
        strcpy(eval1.max.nama, mahasiswa[j].nama);
    }
    if (eval1.min.nilai > mahasiswa[j].eval1)
    {
        eval1.min.nilai = mahasiswa[j].eval1;
        strcpy(eval1.min.nama, mahasiswa[j].nama);
    }
    if (eval2.max.nilai < mahasiswa[j].eval2)
    {
        eval2.max.nilai = mahasiswa[j].eval2;
        strcpy(eval2.max.nama, mahasiswa[j].nama);
    }
    if (eval2.min.nilai > mahasiswa[j].eval2)
    {
        eval2.min.nilai = mahasiswa[j].eval2;
        strcpy(eval2.min.nama, mahasiswa[j].nama);
    }
    if (eval3.max.nilai < mahasiswa[j].eval3)
    {
        eval3.max.nilai = mahasiswa[j].eval3;
        strcpy(eval3.max.nama, mahasiswa[j].nama);
    }
    if (eval3.min.nilai > mahasiswa[j].eval3)
    {
        eval3.min.nilai = mahasiswa[j].eval3;
        strcpy(eval3.min.nama, mahasiswa[j].nama);
    }
    if (uas.max.nilai < mahasiswa[j].uas)
    {
        uas.max.nilai = mahasiswa[j].uas;
        strcpy(uas.max.nama, mahasiswa[j].nama);
    }
    if (uas.min.nilai > mahasiswa[j].uas)
    {
        uas.min.nilai = mahasiswa[j].uas;
        strcpy(uas.min.nama, mahasiswa[j].nama);
    }
    
};

void ceknilai() {
    if (mahasiswa[i].rata_rata >= 86 && mahasiswa[i].rata_rata <= 100)
    {
        strcpy(mahasiswa[i].huruf, "A");
    } 
    else if (mahasiswa[i].rata_rata >= 81 && mahasiswa[i].rata_rata < 86)
    {
        strcpy(mahasiswa[i].huruf, "A-");
    } 
    else if (mahasiswa[i].rata_rata >= 76 && mahasiswa[i].rata_rata < 81)
    {
        strcpy(mahasiswa[i].huruf, "AB");
    } 
    else if (mahasiswa[i].rata_rata >= 71 && mahasiswa[i].rata_rata < 76)
    {
        strcpy(mahasiswa[i].huruf, "B+");
    } 
    else if (mahasiswa[i].rata_rata >= 66 && mahasiswa[i].rata_rata < 71)
    {
        strcpy(mahasiswa[i].huruf, "B");
    } 
    else if (mahasiswa[i].rata_rata >= 61 && mahasiswa[i].rata_rata < 66)
    {
        strcpy(mahasiswa[i].huruf, "BC");
    } 
    else if (mahasiswa[i].rata_rata >= 56 && mahasiswa[i].rata_rata < 61)
    {
        strcpy(mahasiswa[i].huruf, "C");
    } 
    else if (mahasiswa[i].rata_rata >= 41 && mahasiswa[i].rata_rata < 56)
    {
        strcpy(mahasiswa[i].huruf, "D");
    } 
    else
    {
        strcpy(mahasiswa[i].huruf, "E");
    } 
    
}

int main(int argc, char const *argv[])
{
    puts("Selamat Datang di Program Nilai Mahasiswa");
    puts("Oleh Akari Kanzoo Triputra NRP 3124600004");
    puts("=======================================");
    
    while(1){
        menu();
    }
    
    return 0;
}
