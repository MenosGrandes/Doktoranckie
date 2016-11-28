#ifndef SORTINSERTTUPLE_H
#define SORTINSERTTUPLE_H
#include "SortBehaviour.h"
/**
Bierzemy parami. od 2 indeksu.
Porownujemy najwieksza z pary z liczba poprzednia, az do momenu w ktorym liczba porownywana jest wieksza od najwiekszej liczby z pary.
Jezeli liczba bedzie mniejsza, wtedy wstawiamy obie liczby w miejsce ostatniego porownania i porownujemy z liczba mniejsza z pary.
Robimy porownanie mniejszej liczby z pary dopoki liczba z ktora porownujemy jest wieksza od najmniejszej liczby z pary. Jak znajdziemy mniejsza
to znaczy ze za nia trzeba wstawic mniejsza liczbe z pary

*/
class SortInsertTuple : public SortBehaviour
{
public:
    static const SortType m_sortType=TUPLE_INSERT;

    SortInsertTuple() {};
    ~SortInsertTuple() {};

    void sort(std::vector<int> &toSort)
    {

        const int sizeOfArray=toSort.size()-(toSort.size()%2);

//        int counterAll=0, counter1=0, counter2 =0,counter3=0, counter4=0;
        for(int i=0; i<sizeOfArray; i+=2)
        {
//            counterAll++;
            if(toSort[i] > toSort[i+1])
            {
                std::swap(toSort[i],toSort[i+1]);
//                counter1++;
            }
            const int pom1 = toSort[i];
            const int pom2 = toSort[i+1];

            int j = i-1;
            while(j>=0 && toSort[j]>pom2)
            {
                toSort[j+2] =  toSort[j];
                j--;
//                counter2++;
            }
            toSort[j+2] = pom2;
            toSort[j+1] = pom1;

            while(j>=0 && toSort[j]>pom1)
            {
                toSort[j+1] = toSort[j];
                --j;
//                counter3++;
            }
            toSort[j+1] = pom1;
        }
        if(toSort.size()%2==1)
        {
            const int pom = toSort[toSort.size()-1];
            int k = toSort.size()-2;
            while(k>=0 && toSort[k]>pom)
            {
                toSort[k+1] = toSort[k];
                --k;
//                counter4++;
            }
            toSort[k+1] = pom;
        }

//        std::cout<< counterAll<<" "<<counter1<<" "<<counter2<<" "<<counter3<<" "<<counter4<<std::endl;

    }
};

#endif // SORTINSERTTUPLE_H
