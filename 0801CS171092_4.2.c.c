#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node
{
    int a;
    struct node* tarray[26];
    int torf;
};
typedef struct Node node;
int findindex(char a)
{
    return (int)a-(int)'a';
}
node* newnode()
{
    int i;
    node* newn=(node*)malloc(sizeof(node));
    newn->torf=0;
    for(i=0;i<26;i++)
    {
        newn->tarray[i]=NULL;
    }
}
node* insert(node*root,char* key)
{
    int index,i;
    int length=strlen(key);
    node * temp=root;
    for(i=0;i<length;i++)
    {
        index=findindex(key[i]);
        if(temp->tarray[index]==NULL)
        {
            temp->tarray[index]=newnode();
        }
        temp=temp->tarray[index];
    }
    temp->torf=1;
    return root;
}
int search(node* root,char* key)
{
    int index,i;
    int length=strlen(key);
    node* temp=root;
    for(i=0;i<length;i++)
    {
        index=findindex(key[i]);
        if(temp->tarray[index]==NULL)
        {
            return 0;
        }
        temp=temp->tarray[index];
    }
    return (temp!=NULL&&temp->torf);
}




int main()
{
    node* root=newnode();
    FILE *fp=fopen("file1.txt","r");
    if(fp==NULL)
    {
        printf("file not opened\n");
    }
    char word[10000],*value;
    fgets(word,sizeof(word),fp);
    value=strtok(word,",.:; \t\n\'");
    if((value!=NULL)&&((int)value[0]<97))
        value[0]=(char)((int)value[0]+32);
        while(value!=NULL)
        {
            printf("%s\n",value);
            if(value!=NULL)
            {
                root=insert(root,value);
            }
                value=strtok(NULL,",.:; \t\n\'");
                if((value!=NULL)&&((int)value[0]<97))
                    value[0]=(char)((int)value[0]+32);
        }
        fclose(fp);
    int fou=0;
    fp=fopen("file2.txt","r");
    if(fp==NULL)
        printf("file not opened\n");
    fgets(word,sizeof(word),fp);
    value=strtok(word,",.:-; \t\n\'");
    if((value!=NULL)&&((int)value[0]<97))
            value[0]=(char)((int)value[0]+32);
    while(value!=NULL)
    {
        fou=0;
        value=strtok(NULL,",.-:; \t\n\'");
        if((value!=NULL)&&((int)value[0]<97))
                value[0]=(char)((int)value[0]+32);
        if(value!=NULL)
        {
            fou = search(root,value);
            if(fou==0)
            {
                int des;
                printf("the word \"%s\" not found in dictionary\npress 1 to ignore\n",value);
                printf("press 2 to insert\n");
                scanf("%d",&des);
                if(des==2)
                {
                    root=insert(root,value);
                }
            }

        }
    }
    fclose(fp);
}

