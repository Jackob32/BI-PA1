#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

#define true 1
#define false 0

int compareIt ( const void * a, const void * b )
{
    int diff, i = 0;
    int lenA, lenB;
    const char *ia = *(const char **)a;
    const char *ib = *(const char **)b;
    
    char * tmpA = NULL;
    char * tmpB = NULL;

    lenA = strlen ( ia );
    lenB = strlen ( ib );

    setlocale(LC_COLLATE, "cs_CZ.UTF-8");

    if ( ! ( tmpA = ( char * ) malloc ( lenA * sizeof ( char ) ) ) )
    {
        printf ( "Nespravna alokace.\n" );
       /* for ( int i = 0; i < arrSize; i++)
        {
            free ( arr[i] );
        }
        free ( arr );*/
        return 1;
    }

    if ( ! ( tmpB = ( char * ) malloc ( lenB * sizeof ( char ) ) ) )
    {
        printf ( "Nespravna alokace.\n" );
       /* for ( int i = 0; i < arrSize; i++)
        {
            free ( arr[i] );
        }
        free ( tmpA );
        free ( arr );*/
        return 1;
    }


    while( ia[i] ) 
    {
        tmpA[i] = tolower( ia[i] );
        i++;
    }

    i = 0;
    while( ib[i] ) 
    {
        tmpB[i] = tolower( ib[i]);
        i++;
    }

    diff = strcoll ( tmpA ,tmpB );
    free ( tmpA );
    free ( tmpB );
    
    if (diff > 0) return 1;
    if (diff == 0) return 0;



    return -1;
}

int sortIt ( char ** arr, int arrSize )
{
    qsort ( arr, arrSize, sizeof ( char * ), ( int ( * ) ( const void *, const void * ) ) compareIt);
    for ( int i = 0; i < arrSize; i++ )
        printf ( "%s\n", arr[i]);
    
    return 0;
}

int main ( void )
{
    char ** arr;
    char ch;
    int arrSize = 0, arrSizeMax = 5, lineSize = 0, lineSizeMax = 5;

    //alokace pole pro vsechny zpravy (pole poli)
    if ( ! ( arr = ( char ** ) malloc ( arrSizeMax * sizeof ( char * ) ) ) )
    {
        printf ( "Nespravna alokace.\n" );
        return 1;
    }

    for ( int i = 0; i < arrSizeMax; i++)
    {
        if ( ! ( arr[i] = ( char * ) malloc ( lineSizeMax * sizeof ( char ) ) ) )
        {
            printf ( "Nespravna alokace.\n" );

            for ( int i = 0; i < arrSize; i++)
            {
                free ( arr[i] );
            }

            free ( arr );
            return 1;
        }
    }

    while ( 1 )
    {
        ch = getchar ();

        if ( ch == EOF )
        {
            break;
        }

        //realokace pole vsech poli
        if ( arrSize >= arrSizeMax )
            {
                arrSizeMax *= 3;
                if ( ! ( arr = ( char ** ) realloc ( arr, arrSizeMax * sizeof ( char * ) ) ) )
                {
                    printf ( "Nespravna alokace.\n" );
                    for ( int i = 0; i < arrSize; i++)
                    {
                        free ( arr[i] );
                    }
                    free ( arr );
                    return 1;
                }

                for ( int i = arrSize; i < arrSizeMax; i++)
                {
                    if ( ! ( arr[i] = ( char * ) malloc ( lineSizeMax * sizeof ( char ) ) ) )
                    {
                        printf ( "Nespravna alokace.\n" );
                        for ( int i = 0; i < arrSize; i++)
                        {
                            free ( arr[i] );
                        }
                        free ( arr );
                        return 1;
                    }               
                }
            } 

        while ( 1 )
        {
            //po konci radku konec cyklu - nulovani hodnot
            if ( ch == '\n' )
            {
                arr[arrSize][lineSize] = '\0';
                lineSize = 0;
                lineSizeMax = 5;
                break;
            }

            if ( ! ( ( ch >= 'A' && ch <= 'Z' ) || ( ch >= 'a' && ch <= 'z' ) || ch == ' ' ) )
            {
                printf ( "Nespravny vstup.\n" );
                for ( int i = 0; i < arrSize; i++)
                {
                    free ( arr[i] );
                }
                free ( arr );
                return 1;
            }

            //realokce pole pro jeden radek
            if ( lineSize >= lineSizeMax )
            {
                lineSizeMax *= 3;
                if ( ! ( arr[arrSize] = ( char * ) realloc ( arr[arrSize], lineSizeMax * sizeof ( char ) ) ) )
                {
                    printf ( "Nespravna alokace.\n" );
                    for ( int i = 0; i < arrSize; i++)
                    {
                        free ( arr[i] );
                    }
                    free ( arr );
                    return 1;
                }
            }     
            arr[arrSize][lineSize] = ch;
            lineSize++;    
            ch = getchar ();      
        }
            arrSize++;
    }    
    
   // arrSize++;
    
    sortIt ( arr, arrSize);

    for ( int i = 0; i < arrSizeMax; i++)
    {
        free ( arr[i] );
    }
    free ( arr );

}
