//
// Created by Utente on 07/01/2022.
//

#ifndef ES01_DATA_H
#define ES01_DATA_H


typedef struct O{


    int ore;
    int minuti;


}ora;


typedef struct D{

    int giorno;
    int mese;
    int anno;

}data;

void stampaData(data d);


#endif //ES01_DATA_H
