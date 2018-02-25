#include "list.h"
#include "player.h"

void createList(List &L) {
    /**
    * FS : first(L) dan last(L) diset Nil
    */
    //-------------your code here-------------
    first(L) = NULL;
    last(L) = NULL;
    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */

    address P = NULL;
    //-------------your code here-------------
    info(P) = x;
    prev(P) = NULL;
    next(P) = NULL;
    //----------------------------------------
    return P;
}

void deallocate(address &P) {
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //-------------your code here-------------
    delete P;
    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //-------------your code here-------------
    if (first(L) == NULL && last(L) == NULL ){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
        next(last(L)) = first(L);
        prev(P) = last(L);
    }
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //-------------your code here-------------
    if (first(L) == NULL && last(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
        next(last(L)) = first(L);
        prev(first(L)) = next(last(L));
    }
    //----------------------------------------
}

address findElmByID(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //-------------your code here-------------
    if (first(L)== NULL && last(L) == NULL){
        cout<<"data kosong";
    }else{
        P = first(L);
        while(next(P) != NULL && P->info.ID != x.ID){
            P = next(P);
        }if(P->info.ID == x.ID){
            return P;
        }else{
            return NULL;
        }
    }
    //----------------------------------------
}

address findElmByName(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.name = x.name,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //-------------your code here-------------
    if (first(L)== NULL && last(L) == NULL){
        cout<<"data kosong";
    }else{
        while(next(P) != NULL && P->info.name != x.name){
            P = next(P);
        }if(P->info.name == x.name){
            return P;
        }else{
            return NULL;
        }
    }
    //----------------------------------------
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if(first(L) == NULL && last(L) == NULL){
        cout<<"data kosong";
    }else{
        P=first(L);
        if(first(L)==last(L)){
            prev(P) = NULL;
            next(P) = NULL;
            first(L) = NULL;
            last(L) = NULL;
        }else{
            first(L) = next(P);
            prev(P) = NULL;
            next(P) = NULL;
            first(L) = NULL;
            last(L) = NULL;
            next(last(L)) = first(L);
            prev(first(L)) = last(L);
        }
    }
    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if(first(L) == NULL && last(L) == NULL){
        cout<<"data kosong";
    }else{
        P = last(L);
        last(L) = prev(P);
        prev(P) = NULL;
        next(P) = NULL;
        next(last(L)) = first(L);
        prev(first(L)) = last(L);
    }
    //----------------------------------------
}

void insertAfter(List &L, address &Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //-------------your code here-------------
    if(first(L) == NULL && last(L) == NULL){
        insertFirst(L,P);
    }else if(Prec == last(L)){
        insertLast(L,P);
    }else{
        next(P) = next(Prec);
        next(Prec) = P;
        prev(P) = prev(next(Prec));
    }
        next(last(L)) = first(L);
        prev(first(L)) = last(L);
    //----------------------------------------

}
void deleteAfter(List &L, address &Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if(first(L) == NULL && last(L) == NULL){
        cout<<"data kosong";
    }else{
        if(first(L) == last(L)){
            deleteFirst(L,P);
        }else if(next(first(L))= last(L)){
            deleteLast(L,P);
        }else{
            P = next(Prec);
            next(Prec) = next(P);
            prev(next(P)) = Prec;
            prev(P) = NULL;
            next(P) = NULL;
        }
        next(last(L)) = first(L);
        prev(first(L)) = last(L);
    }
    //----------------------------------------
}

