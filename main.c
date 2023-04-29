#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void oyun(int a,int b,int *c,int *d)//girilen parametrelere karsilik gelen fonksiyonun parametreleri.
{

    while(1){//main fonksiyonundaki while döngüsü bitene kadar sonsuz kez devam eden döngü.

        if( (a==1 && b==1) || (a==2 && b==2) || (a==3 && b==3) ){//beraberlik durumunda.
             printf("Oyun berabere kaldi.\n");
                if(a==1 && b==1)
                    printf("Bilgisayar-->Tas yapti.\nSiz-->Tas yaptiniz.\n");//ikisi de tas yaparsa
                else if(a==2 && b==2)
                    printf("Bilgisayar-->Kagit yapti.\nSiz-->Kagit yaptiniz.\n");//ikisi de kagit yaparsa
                else if(a==3 && b==3)
                    printf("Bilgisayar-->Makas yapti.\nSiz-->Makas yaptiniz.\n");//ikisi de makas yaparsa

              break;

            }

        else if(a==1 && b==3 ){//bilgisayar kullaniciyi yenerse bilgisayarýn skorunu bir arttirir.
             printf("Bilgisayar-->Tas yapti.\nSiz-->Makas yaptiniz.\n");
             printf("Oyunu bilgisayar kazandi.\n");
             (*c)++;
             break;}

        else if(a==2 && b==1 ){//bilgisayar kullaniciyi yenerse bilgisayarýn skorunu bir arttirir.
             printf("Bilgisayar-->Kagit yapti.\nSiz-->Tas yaptiniz.\n");
             printf("Oyunu bilgisayar kazandi.\n");
             (*c)++;
              break;}

        else if(a==3 && b==2 ){//bilgisayar kullaniciyi yenerse bilgisayarýn skorunu bir arttirir.
             printf("Bilgisayar-->Makas yapti.\nSiz-->Kagit yaptiniz.\n");
             printf("Oyunu bilgisayar kazandi.\n");
             (*c)++;
              break;}

        else if(a==3 && b==1 ){//kullanici bilgisayari yenerse kullanicinin skorunu bir arttirir.
             printf("Bilgisayar-->Makas yapti.\nSiz-->Tas yaptiniz.\n");
             printf("Oyunu siz kazandiniz.\n");
             (*d)++;
              break;}

        else if(a==1 && b==2 ){//kullanici bilgisayari yenerse kullanicinin skorunu bir arttirir.
             printf("Bilgisayar-->Tas yapti.\nSiz-->Kagit yaptiniz.\n");
             printf("Oyunu siz kazandiniz.\n");
             (*d)++;
              break;}

        else if(a==2 && b==3 ){//kullanici bilgisayari yenerse kullanicinin skorunu bir arttirir.
             printf("Bilgisayar-->Kagit yapti.\nSiz-->Makas yaptiniz.\n");
             printf("Oyunu siz kazandiniz.\n");
             (*d)++;
              break;}
    }


}


int main()
{

    printf("****TAS KAGIT MAKAS OYUNU****\n\n");
    srand(time(0));//Rastgele sayi üretme fonksiyonu

    int sayac_pc=0,sayac_k=0 ;//sayac_pc:bilgisayarin skorunu tutar,sayac_k:kullanicinin skorunu tutar.
    int a,b;//a:bilgisayarin sectigi deger,b:kullanicinin sectigi deger.
    int pc[100],k[100];//bilgisayar ve kullanicidan alinan degerleri tutmak icin acilan diziler.
    int e=0,f=0;//yukaridaki dizilerin sayaclari.

    while((sayac_pc < 5) && (sayac_k < 5)){//döngüyü iki taraftan birinin skoru 5 oluncaya kadar calistiriyor.

    a=((rand()%3)+1);//bilgisayara 1 ile 3 arasinda rastgele sayi ürettiriyor.

    printf("1-Tas 2-Kagit 3-Makas \nHangisini secmek istiyorsan numarasini giriniz:");
    scanf("%d",&b);//kullanici deger giriyor.
    printf("\n");

    pc[e++]=a;//bilgisayardan  alinan degerleri diziye yerlestirir.
    k[f++]=b;//kullanicidan bilgisayardan  alinan degerleri diziye yerlestirir.


    if(b>0 && b<4){//kullanicidan alinan degerler 1 ile 4 arasinda olmali.

        oyun(a,b,&sayac_pc,&sayac_k);//parameteler fonksiyona aktarilir.

        printf("Skor--->  |Bilgisayar->%d : %d<-Siz|\n\n",sayac_pc,sayac_k);//oynanan elin skorunu yazdirir.

    }

    else
        printf("Hatali deger girdiniz!!! \n\n");// b 0 ile 4 arasinda degil ise hata verir.

    }


    if(sayac_pc == 5)//bilgisayar skoru 5 olursa oyun biter genel skoru yazdirir.
            printf("GENEL SKOR ---> Bilgisayar | %d : %d | Oyuncu \nGenel oyunu Bilgisayar kazandi. ",sayac_pc,sayac_k);

    else if (sayac_k == 5)//kullanici skoru 5 olursa oyun biter genel skoru yazdirir.
            printf("GENEL SKOR ---> Oyuncu | %d : %d | Bilgisayar \nGenel oyunu Siz kazandiniz. ",sayac_k,sayac_pc);


    return 0;
}
