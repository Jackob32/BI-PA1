#include <stdio.h>
#include <string.h>

int countIt ( int map[][2000], int x1, int y1, int x2, int y2 )
{
    int sum = 0, y, x;
     for ( x = x1 ; x <= x2; x++ )
    {
        for ( y = y1 ; y <= y2; y++ )
        {
            sum = sum + map[x][y];
            if ( ( y - 1 ) == y2 ) sum = 0;
        }
    }
    return sum;
}

int tryEverything ( int map[][2000], int rows, int cols, int price, int * count, char questions[10] )
{
    int x1, x2, y1, y2;
    for ( x1 = 0; x1 < rows; x1++ )
    {
        for ( y1 = 0; y1 < cols; y1++ )
        {
            for ( x2 = x1; x2 < rows; x2++ )
            {
                for ( y2 = y1; y2 < cols; y2++ )
                {
                    if ( price == countIt ( map, x1, y1, x2, y2 ) )
                    {
                         
                        (*count)++;
                        if ( strcmp ( questions, "list" ) == 0 ) 
                        {
                            printf ( "%d @ (%d,%d) - (%d,%d)\n", price, y1, x1, y2, x2 );
                            
                            
                        } else if ( strcmp ( questions, "count" ) == 0 )
                        {
                            
                        } else 
                        {
                            printf ( "Nespravny vstup.\n" );
                            return 1;   
                        }
                    }
                }
            }   
        }
    }
    printf ( "Celkem: %d\n", *count );
    return 0;
}

int main ( void )
{
    int rows, cols, i, j = 0, price;
    char questions[10];
    static int map[2000][2000];
    int count = 0;

    printf ( "Velikost mapy:\n" );
    
    if ( scanf ( "%d %d", &cols, &rows ) != 2 || rows < 1 || rows > 2000 || cols < 1 || cols > 2000  )
    {
        printf ( "Nespravny vstup.\n" );
        return 1;
    }

    printf ( "Cenova mapa:\n" );

    for ( i = 0; i < rows; i++ )
    {
        for ( j = 0; j < cols; j++ )
        {
            if ( scanf ( "%d", &map[i][j] ) != 1 )
            {
                printf ( "Nespravny vstup.\n" );
                return 1;
            }
        }
    }

    printf ( "Dotazy:\n" );

    while ( scanf("%9s", questions) != EOF )
    {
        count = 0;
        
         if ( ( strcmp(questions, "count") != 0 && strcmp(questions, "list") != 0 ) || scanf( "%d", &price ) != 1 )
         {
             printf ( "Nespravny vstup.\n");
             return 1;
         }

        tryEverything ( map, rows, cols, price, &count, questions );
        
        
    }
   
    return 0;
}
