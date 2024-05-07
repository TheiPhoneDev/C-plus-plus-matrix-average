#include <iostream>

using namespace std;

const int righeMax=3;
const int colonneMax=4;

//prototipi
void caricaMatrice(int matrix[righeMax][colonneMax]);
void visualizzaMatrice(int matrix[righeMax][colonneMax]);
void caricaVR(int matrix[righeMax][colonneMax], float vr[righeMax]);
void caricaVC(int matrix[righeMax][colonneMax], float vc[colonneMax]);
void mediaTotale(int matrix[righeMax][colonneMax]);
int Menu();

int main() {

  int scelta;
  int matrix[righeMax][colonneMax];
  float VR[righeMax];
  float VC[colonneMax];

  do {
    scelta=Menu();
    switch(scelta) {
      case 1:
        caricaMatrice(matrix);
      break;
      case 2:
        visualizzaMatrice(matrix);
      break;
      case 3:
        caricaVR(matrix,VR);
      break;
      case 4:
        caricaVC(matrix,VC);
      break;
      case 5:
        mediaTotale(matrix);
      break;
      case 0:
        cout<<"Esci"<<endl;
      break;
      default:
        cout<<"Attenzione, scelta sbagliata!"<<endl;
      break;
    }
  }while(scelta!=0);

}


int Menu() {
  int scegli;
  cout<<"-----------------MENU-----------------"<<endl;
  cout<<"1-Carica matrice"<<endl;
  cout<<"2-Visualizza matrice"<<endl;
  cout<<"3-Media per righe"<<endl;
  cout<<"4-Media per colonne"<<endl;
  cout<<"5-Media totale"<<endl;
  cout<<"0-Fine"<<endl;
  cout<<"Scegli un operazione: "<<endl;
  cin>>scegli;

  return scegli;
}


void caricaMatrice(int matrix[righeMax][colonneMax]) {

  cout<<endl;

  for(int i=0; i<righeMax; i++) {
    for(int j=0; j<colonneMax; j++) {
      cout<<"Inserisci il valore della cella "<<i+1<<" "<<j+1<<": ";
      cin>>matrix[i][j];
    }
  }


  cout<<endl;

}

void visualizzaMatrice(int matrix[righeMax][colonneMax]) {

  cout<<endl;

  for(int i=0; i<righeMax; i++) {
    for(int j=0; j<colonneMax; j++) {
      cout<<matrix[i][j]<<"\t";
    }
    cout<<endl;
  }

  cout<<endl;

}

void caricaVR(int matrix[righeMax][colonneMax], float vr[righeMax]) {

    float somma;
    float media=0;

    for(int i=0; i<righeMax; i++) {
      somma=0;
      for(int j=0; j<colonneMax; j++) {
        somma=somma+matrix[i][j];
        media=float(somma/colonneMax);
        vr[i]=media;
      }
    }

    cout<<endl;

    cout<<"---------------VETTORE RIGHE---------------"<<endl;

    for(int i=0; i<righeMax; i++) {
        cout<<vr[i]<<endl;
    }

}


void caricaVC(int matrix[righeMax][colonneMax], float vc[colonneMax]) {

  float somma;
  float media=0;

    for(int i=0; i<colonneMax; i++) {
      somma=0;
      for(int j=0; j<righeMax; j++) {
        somma=somma+matrix[j][i];
        media=float(somma/righeMax);
        vc[i]=media;
      }
    }

    cout<<endl;

    cout<<"---------------VETTORE COLONNE---------------"<<endl;

    for(int i=0; i<colonneMax; i++) {
        cout<<vc[i]<<endl;
    }
}


void mediaTotale(int matrix[righeMax][colonneMax]) {
  float somma=0;
  float media;

  for(int i=0; i<righeMax; i++) {
    for(int j=0; j<colonneMax; j++) {
      somma=somma+matrix[i][j];
    }
  }

  media=float(somma/(righeMax*colonneMax));

  cout<<endl;

  cout<<"La media totale degli elementi contenuti nella matrice e' : "<<media<<endl;

  cout<<endl;
}
