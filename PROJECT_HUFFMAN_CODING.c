
#include <stdio.h>

#include <string.h>

#include<stdlib.h>


int i = 0 , j = 0 , count[256] = {0} ;

float before = 0 , after = 0 ;

char filename[20];


struct tree

{

int x ;

char ch ;

struct tree *right , *left , *next ;

} *root = NULL , *temp , *treem , *end , *temps ;




struct arrays

{

 int a ;

 char bin[30] ;

 struct arrays *next2 ;

} *start = NULL , *end2 , *tempar ;




void compression_factor()

{
    char x;

    float cf ;

    FILE *f ;

    f = fopen( "compressed_one.txt" , "r" );

    while( ( x = fgetc(f) )!= EOF)

        after++ ;

    cf = (float) ( before - after ) * 100 / before ;

    printf( " \n\n\n\nCompression Factor ( Extent of compression ) is  :  %lf %\n\n " , cf ) ;

}






void arrays_made()

{

  int x ;

  FILE *f1 , *f2 ;

  f2 = fopen( "binmade.txt" , "r" ) ;

  f1 = fopen( "char.txt" , "r" ) ;

  //if( count[i] != 0 )
  while( (fscanf(f1 , "%d" , &x)) != EOF )

  {

  tempar = ( struct arrays* )malloc( sizeof( struct arrays ) ) ;

  tempar -> next2 = NULL ;

  tempar -> a = x ;

  i = 0 ;

  //fgets(tempar->bin,30,f2);

  char p ;

  while( ( p = fgetc(f2) ) != '\n' )

  {

      tempar->bin[i]=p;

      i++;

  }

  tempar->bin[i]='\0';

//  fscanf(f2 , "%ld" , &tempar -> bin);

//  printf("\n\nye hai %ld\n",tempar->bin);

  //tempar -> right = NULL;

  //tempar -> left = NULL ;

   if( start == NULL)

   {

   start = tempar ;

   end2 = tempar;

   }

   else

   {

   end2 -> next2 = tempar ;

   end2 = tempar ;

   }

  }

 fclose(f1) ;

 fclose(f2) ;

}




void print2()

{

  printf( "\n\n\n" ) ;

  if( start == NULL )

  {

  printf( "Empty list. " ) ;

  }

  else

  {

   tempar = start ;

   while( tempar != NULL )

   {

   printf( " \n %-5c has   %-15s   binary code." , tempar -> a , tempar -> bin ) ;

   tempar = tempar -> next2 ;

   }


  }

}



void file_in_binarylang()
{
 char x;
 FILE *fa,*fb;
 //tempar=start;
 fa=fopen(filename,"r");

 fb=fopen("binaryfile.txt","w");
// printf("dekh dekh %c",start->a);
 while( ( x = fgetc(fa))!= EOF )
 {
     //printf("%c",x) ;
     before++;
     tempar = start ;
   //  printf("%d",tempar->a);
     while( tempar != NULL )

     {
         //
         if( (int)x == tempar -> a )
            {

            fprintf( fb , "%s" , tempar->bin ) ;

            break ;

            }

         tempar = tempar -> next2 ;

     }

   //fseek(fb,-1,SEEK_CUR);

 }

 fclose(fa) ;

 fclose(fb) ;

}




void space()
{

  char x ;

  int i = 0 ;

  FILE *fa , *fb ;

  fa = fopen( "binaryfile.txt","r" ) ;

  fb = fopen( "binaryfilespaced.txt" , "w" ) ;

  while( (x=fgetc(fa) ) != EOF )

  {

    i++ ;

    putc( x , fb ) ;

    if(i==32)

   {

       i=0;

       putc(' ',fb);

   }

  }

    fclose(fa);

    fclose(fb);


}



int binary_decimal(long int n)
 {
    int decimal=0, i=0, rem;

    while (n!=0)
    {
        rem = n % 10;

        n/=10;

        decimal = decimal + rem*pow(2,i) ;

    //    printf( " %d " , decimal ) ;

        ++i ;

    }

    return decimal ;

}








void compress()
{
    long int p;

    int k;

    FILE *fa,*fb;

    fa=fopen("binaryfilespaced.txt","r");

    fb=fopen("compressed_one.txt","w");

    while((fscanf(fa,"%ld",&p))!=EOF)

    {

      k=binary_decimal(p);
     //  printf("\n%d\t",k);

      fprintf(fb,"%d",k);

    }


    fclose(fa);

    fclose(fb);

}





int frequency()

{

   char ch ;

   printf("\n\n\n\nEnter the File name to be compressed :    ");

   gets(filename);

   strcat(filename,".txt");
   FILE *f ;

   f = fopen(filename, "r") ;

   while ( (ch = getc(f)) != EOF )

   {

      if ( ch >= 0 && ch <= 255 )

         count[ch]++ ;

         i++ ;

   }




/*   for (c = 0; c < 256; c++)

   {



      if (count[c] != 0)

         printf("%c occurs %d times\n",c,count[c]);

   }

*/

   return 0 ;

}



int single()

{

 for( i=0 ; i<=255 ; i++ )

  if( count[i] != 0 )

  {

  temp = ( struct tree* )malloc( sizeof( struct tree ) ) ;

  temp -> next = NULL ;

  temp -> ch = i ;

  temp -> x = count[i] ;

  temp -> right = NULL;

  temp -> left = NULL ;

   if( root == NULL)

   {

   root = temp ;


   end = temp;

   }

   else

   {


   end -> next = temp ;

   end = temp ;

   }

  }

 return 0 ;

}





void sort()

{

 int n = 1 , p , q , i , j ;

 temp = root ;

 while( temp -> next != NULL )

 {

 temp = temp-> next ;

 n++ ;

 }


 for( i=0 ; i < n-1 ; i++ )

{

 temps = root ;

 temp = root -> next ;

 for( j=0 ; j < n-i-1 ; j++ )

{

if( temps -> x > temp -> x)

 {

 q = temps -> ch ;

 temps -> ch = temp -> ch ;

 temp -> ch = q ;

 p = temps -> x ;

 temps -> x = temp -> x ;

 temp -> x = p ;

 }

 temps = temps -> next ;

 temp = temp -> next ;

}

}

}





 void print()

{

  if( root == NULL )

  {

  printf( "Empty list. " ) ;

  }

  else

  {

   temp = root;

   while( temp != NULL )

   {

   printf( "%-5c occurs %-5d times\n" , temp->ch , temp->x ) ;

   temp = temp -> next ;

   }


  }

}





void treemake()

{

do

{

treem = ( struct tree* )malloc( sizeof( struct tree ) ) ;

treem -> left = root ;

treem -> right = root -> next ;

treem -> x = treem -> right -> x + treem -> left -> x ;

root = treem -> right -> next ;

treem -> right -> next = NULL ;

treem -> left -> next = NULL ;

//treem->left->cp='0';

//treem->right->cp='1';

insert() ;   //treem insertion :)

}while( root -> next != NULL ) ;

//root->cp=3;
}





//INSERTING NODE



void insert()

{

    struct tree *current ;

    if ( root == NULL || root -> x >= treem -> x )

    {

        treem -> next = root ;

        root = treem ;

    }

    else

    {

        current = root;

        while ( current -> next != NULL && current -> next -> x < treem -> x )

        {

            current = current -> next ;

        }

        treem -> next = current -> next ;

        current -> next = treem ;

    }

}






/*
void postorder(struct tree *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display ");
        return;
    }
    if (t->left != NULL)
        postorder(t->left);
    if (t->right != NULL)
        postorder(t->right);
    printf("%d ", t->x);
}

*/



void LastTreeRightNode()
{

temps=root;

while(temps->right!=NULL)

temps=temps->right;
//return temp;
}


/*
int countnodes( struct tree *n )
{
    int c = 1 ;

    if (n == NULL)

        return 0 ;
    else

    {
        c += countnodes( n -> left ) ;

        c += countnodes( n-> right ) ;

        return c ;

    }

}
*/




    //  USE OF STACK IS HERE IN THE assignbinary FUNCTION BELOW  //



void assign_binary( struct tree *t , int *arr , int top , FILE *f1 , FILE *f2 )
{

if( t==temp )
return;



if( t -> left != NULL )

{

arr[top] = 0 ;

assign_binary( t->left , arr , top+1 , f1 , f2 ) ;

}

if( t -> right != NULL )

{

arr[top] = 1 ;

assign_binary( t->right , arr ,top+1 , f1 , f2 ) ;

}


if( t->left == NULL && t->right == NULL )

{

printf( "\n%-5c\t%-5d\t" , t -> ch , t -> x ) ;

fprintf(f1,"%d",t->ch);

putc('\n',f1);

for( i = 0 ; i < top ; i++ )

{

printf( "%d" , arr[i] ) ;

fprintf(f2,"%d",arr[i]);
//putw(arr[i],f2) ;

}
putc('\n',f2);

top = 0 ;

}

}




int main()

{

printf( "\n\n  Project Created By  :  ANSHUL TIWARI  (14104030)" ) ;


frequency() ;

single() ;

sort() ;

print() ;

printf( "\n\nMade Tree\n\n" ) ;

treemake() ;

//postorder(root);

//preorder

LastTreeRightNode() ;

int *arr = ( int * )malloc( 127*sizeof( int ) ) ;

FILE *f1 , *f2 ;

f1 = fopen( "char.txt" , "w" ) ;

f2 = fopen( "binmade.txt" , "w" ) ;

assign_binary( root ,arr,0, f1 , f2 ) ;

fclose(f1) ;

fclose(f2) ;

arrays_made() ;

print2() ;

file_in_binarylang() ;

space() ;

compress() ;

compression_factor();

//printLeaves();

//printf("\nP: \n\n");

//printleaves(root);

free(temp) ;

free(temps) ;

free(tempar) ;

printf( "\n\n\n\n" ) ;

printf( "                               T H A N K    Y O U\n\n\n\n" ) ;

return 0 ;

}
