

void create(TREE*t)
   {
     int op;
     static int lev;
     TREE *temp;
       lev++;
       system("clear");
       printf("\n\n\t      %s    in LEVEL  %d \n\n",t->data,lev);
       printf("\n Do you want to create  >>LEFT  CHILD<< FOR  THIS PARENT      YES (1) : ");
       scanf("%d",&op);
        if(op==1)
         {
                                                                                                 
          temp=(TREE*) malloc(sizeof(TREE));
          printf("\n\n  Enter the  DATA  : ");
          scanf("%s",temp->data);
          (temp)->Lchild=(temp)->Rchild=NULL;
           temp->flag=0;
           temp->level=lev+1;
           t->Lchild=temp;
           create(temp);
         }
       system("clear");
       printf("\n\n\t      %s    in LEVEL  %d \n\n",t->data,lev);

	  printf("\n Do you want to create >>RIGHT  CHILD<< FOR  THIS PARENT      YES (1) : ");
       scanf("%d",&op);
        if(op==1)
         {
                                                                                                 
          temp=(TREE*) malloc(sizeof(TREE));
          printf("\n\n  Enter the  DATA  : ");
          scanf("%s",temp->data);
          (temp)->Lchild=(temp)->Rchild=NULL;
           temp->flag=0;
           temp->level=lev+1;
           t->Rchild=temp;
           create(temp);
         }
     if(tree_level<lev)
      tree_level=lev;
     lev--;
    }

