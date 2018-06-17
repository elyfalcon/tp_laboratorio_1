#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this, void* pElement)
{
    int returnAux = -1;

    int flag=0;
    void** aux;

    if(this!=NULL && pElement!=NULL)
    {
        if(this->size == this->reservedSize)
        {
            if(resizeUp(this))// devuelve 0 si da ok
           {
             flag=1;// marca que no agregue el elemento porque no hay espacio
           }

        }
        if(flag==0)
            {
        *(this->pElements+this->size)=pElement;
           this->size++;
           returnAux=0;

       }


 /*       if(aux!=NULL)
        {
        }*/
    }



    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL)
        {
        free(this);
        returnAux=0;
        }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux=this->size;

    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;


    if(this!=NULL && index>=0 && index<this->size) //es < estricto porque size apunta al proximo valor
    {
        returnAux=this->pElements[index];
    }

    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if(this!=NULL && pElement!=NULL)
    {
        returnAux=0;
        for(i=0;i<this->size;i++)
        {
            if(this->get(this,i)==pElement)
            {
                returnAux=1;
                break;
            }//fin if(this->)
        }//fin for
    }//fin if(this!=)

    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int returnAux = -1;

    if(this!=NULL && pElement!=NULL)
    {
        if(index<(this->size) && index>=0)
          {
              *(this->pElements+index)=pElement;
              returnAux=0;
          }
    }

    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    int returnAux = -1;
    int i;
    int metrica;


    if(this!=NULL && index>=0 && index<this->size)
    {
        metrica=this->reservedSize-this->size;
        for(i=index;i<this->size;i++)
        {
          /*  if(this->pElements[i]==this->pElements[index])
            {
                free(this->pElements[i]);
                this->pElements[i]=NULL;
                returnAux=0;
            }*/
            this->pElements[i]=this->pElements[i+1];
        }//fin for
        this->size--;
        returnAux=0;
    }//fin if(this!
/*
    if(metrica==0)
    {
        pElements=realloc(pElements,reserveSize+)
    }   */

    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        free(this->pElements);
        this->size=0;
        returnAux=0;
    }

    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;

    int i;

    if(this!=NULL)
    {
     returnAux=al_newArrayList();
    for(i=0;i<this->len(this);i++)
    {
       al_add(returnAux,this->pElements[i]);

     }//fin for
    }//fin if(this!)*/

    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL && pElement!=NULL && index<=this->size && index >=0)
    {
        if(this->size==this->reservedSize)
        {
            resizeUp(this);
        }
    if(index < this->size)
    {
        al_set(this->pElements,index,pElement);
    }
    else
        if(index==this->size)
    {
        al_add(this,pElement);
    }

        returnAux=0;
    }//fin if(this!)

    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if(this!=0)
    {
        for(i=0;i<=this->len(this);i++)
        {
            if(this->pElements[i]==pElement)
            {
            returnAux=i;
            break;
            }
        }//fin for
    }//fin if

    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(this->len(this)==0)
            returnAux=1;
        else
            if(this->len(this)>0)
            returnAux=0;
    }

    return returnAux;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;

    if(this!=NULL && index >=0 && index<this->len(this))
    {   returnAux=*(this->pElements+index);
        al_remove(this,index);
    }
    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    ArrayList* returnAux = NULL;

    int cant,i;
    if(this!=NULL)
    {

        if(from>=0 && from<to && from<this->len(this) && to >from && to<=this->len(this))
        {
        returnAux=al_newArrayList();
        //cant=this->size;
          for(i=from;i<to;i++)
          {
              al_add(returnAux,this->pElements[i]);
          }//fin for(i=from)

        }//fin if from
    }//fin this!


    return returnAux ;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int returnAux = -1;
    int i,cont=0;

    if(this!=NULL && this2!=NULL)
    {
        returnAux=0;

        if(this->len(this) >= this2->len(this2) && this->len(this)>0 && this2->len(this2) >0)
        {
            for(i=0;i<this->len(this);i++)
            {
                if(al_contains(this,al_get(this2,i))==1)
                   cont++;
            else
               {
                break;
                }
            }//fin for(i=0)

            if(cont==this2->len(this2))
            {
                returnAux=1;
            }

        }//fin if(cant<)
        else
        returnAux=0;

    }//fin if(this)


    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    int* aux;
    int i,j;


    if(this->size != NULL && pFunc!=NULL)
    {
    aux=(void*)malloc(sizeof(int));
        for(i=0;i<=this->len(this)-1;i++)
        {
            for(j=i+1;j<this->len(this);j++)
            {
                if(order==0)
                {
                if(pFunc(this->get(this,i),this->get(this,j))==-1);
                {
                    aux=this->get(this,i);
                    this->pElements[i]=this->pElements[j];
                    this->pElements[j]=aux;
                }//fin if
                }
                if(order==1)
                {
                if(pFunc(this->get(this,i),this->get(this,j))==1);
                {
                    aux=this->get(this,j);
                    this->pElements[i]=this->pElements[j];
                    this->pElements[j]=aux;
                }
                }//fin if
            }//fin 1er for
            } //fin 2do for

        }//fin 1er for


    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;
    void** aux;

    //aux = (void**)realloc(this->pElements, sizeof(void*)*(this->reservedSize + AL_INCREMENT));

    aux = realloc(this->pElements, sizeof(void*)*(this->reservedSize + AL_INCREMENT));

    if(aux != NULL)
    {

        this->reservedSize+= AL_INCREMENT;

        this->pElements = aux;

        returnAux = 0;

    }
    return returnAux;

}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int returnAux = -1;
    int i;

    if(index!=NULL && index < this->len(this) && this!=NULL)
    {

        for(i=this->len(this);i>index;i--)
        {
            if(i==this->len(this))
            {
               if(al_add(this,al_get(this,i))==0)
               returnAux=0;

            }//fin if(i==)
            else
            {
                 //this->pElements[i+1]=this->pElements[i];
                 if(al_set(this,i+1,al_get(this,i))==0)
                    returnAux=0;
            }

        }//fin for

    }//fin if(index

    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int returnAux = -1;

    return returnAux;
}
