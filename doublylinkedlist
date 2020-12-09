#include<stdio.h>
#include<stdlib.h>
struct node
{
  int info;
  struct node *llink;
  struct node *rlink;
};
typedef struct node *NODE;
NODE getnode ()
{
  NODE x;
  x = (NODE) malloc (sizeof (struct node));
  if (x == NULL)
    {
      printf ("Memory is Full!\n");
      exit (0);
    }
  return x;
}

void freenode (NODE x)
{
  free (x);
}

NODE dinsert_front (int item, NODE head)
{
  NODE temp, cur;
  temp = getnode ();
  temp->info = item;
  cur = head->rlink;
  head->rlink = temp;
  temp->llink = head;
  temp->rlink = cur;
  cur->llink = temp;
  return head;
}

NODE dinsert_rear (int item, NODE head)
{
  NODE temp, cur;
  temp = getnode ();
  temp->info = item;
  cur = head->llink;
  head->llink = temp;
  temp->rlink = head;
  temp->llink = cur;
  cur->rlink = temp;
  return head;
}

NODE ddelete_front (NODE head)
{
  NODE cur, next;
  if (head->rlink == head)
    {
      printf ("empty\n");
      return head;
    }
  cur = head->rlink;
  next = cur->rlink;
  head->rlink = next;
  next->llink = head;
  printf ("Deleted node is %d", cur->info);
  freenode (cur);
  return head;
}

NODE ddelete_rear (NODE head)
{
  NODE cur, prev;
  if (head->rlink == head)
    {
      printf ("empty\n");
      return head;
    }
  cur = head->llink;
  prev = cur->llink;
  head->llink = prev;
  prev->rlink = head;
  printf ("Deleted node is %d", cur->info);
  freenode (cur);
  return head;
}

NODE insert_leftpos (int item, NODE head)
{
  NODE temp, cur, prev;
  if (head->rlink == head)
    {
      printf ("List is Empty\n");
      return head;
    }
  cur = head->rlink;
  while (cur != head)
    {
      if (item == cur->info)
	break;
      cur = cur->rlink;
    }
  if (cur == head)
    {
      printf ("Key was not found\n");
      return head;
    }
  prev = cur->llink;
  printf ("Enter Item towards Left of %d :", item);
  temp = getnode ();
  scanf ("%d", &temp->info);
  prev->rlink = temp;
  temp->llink = prev;
  cur->llink = temp;
  temp->rlink = cur;
  return head;
}

NODE insert_rightpos (int item, NODE head)
{
  NODE temp, cur, prev;
  if (head->llink == head)
    {
      printf ("List is Empty\n");
      return head;
    }
  cur = head->llink;
  while (cur != head)
    {
      if (item == cur->info)
	break;
      cur = cur->llink;
    }
  if (cur == head)
    {
      printf ("Key was not found\n");
      return head;
    }
  prev = cur->rlink;
  printf ("Enter Item towards Right of %d :", item);
  temp = getnode ();
  scanf ("%d", &temp->info);
  prev->llink = temp;
  temp->rlink = prev;
  cur->rlink = temp;
  temp->llink = cur;
  return head;
}

NODE delete_all_key (int item, NODE head)
{
  NODE prev, cur, next;
  int count;
  if (head->rlink == head)
    {
      printf ("List is Empty.");
      return head;
    }
  count = 0;
  cur = head->rlink;
  while (cur != head)
    {
      if (item != cur->info)
	cur = cur->rlink;
      else
	{
	  count++;
	  prev = cur->llink;
	  next = cur->rlink;
	  prev->rlink = next;
	  next->llink = prev;
	  freenode (cur);
	  cur = next;
	}
    }
  if (count == 0)
    printf ("Key was not found");
  else
    printf ("Key found in %d Position(s) are Deleted\n", count);
  return head;
}
void dsearch(int item,NODE head)
{
	NODE cur;
	int count;
	if (head->rlink==head)
	{
		printf("List is empty\n");
	}
	cur=head->rlink;
	count=1;
	while (cur!=head && cur->info!=item)
	{
		cur=cur->rlink;
		count++;
	}
	if (cur==head)
	{
		printf("Search unsuccessfull\n");
	}
	else
	{
		printf("Key element found at the position %d\n",count);
	}
}
void display (NODE head)
{
  NODE temp;
  if (head->rlink == head)
    {
      printf ("List is Empty. Cannot Display Items.\n");
      return;
    }
  printf ("Contents of List:\n");
  temp = head->rlink;
  while (temp != head)
    {
      printf ("%d ", temp->info);
      temp = temp->rlink;
    }
  printf ("\n");
}

void main ()
{
  NODE head, last;
  int item, choice;
  head = getnode ();
  head->rlink = head;
  head->llink = head;
  for (;;)
    {
      printf
	("\n1.Insert Front\n2.Insert Rear\n3.Insert Left of Node\n4.Insert Right of Node\n5.Delete Front\n6.Delete Rear\n7.Delete Duplicates\n8.Display\n9.Search\n");
      printf ("Enter Choice :");
      scanf ("%d", &choice);
      switch (choice)
	{
	case 1:
	  printf ("Enter the Item to insert at Front end :");
	  scanf ("%d", &item);
	  last = dinsert_front (item, head);
	  break;
	case 2:
	  printf ("Enter the Item to insert at Rear end :");
	  scanf ("%d", &item);
	  last = dinsert_rear (item, head);
	  break;
	case 3:
	  printf ("Enter the Key Item :");
	  scanf ("%d", &item);
	  head = insert_leftpos (item, head);
	  break;
	case 4:
	  printf ("Enter the Key Item :");
	  scanf ("%d", &item);
	  head = insert_rightpos (item, head);
	  break;
	case 5:
	  last = ddelete_front (head);
	  break;
	case 6:
	  last = ddelete_rear (head);
	  break;
	case 7:
	  printf ("Enter the Key Item to be Deleted:");
	  scanf ("%d", &item);
	  delete_all_key (item, head);
	  break;
	case 8:
	  display (head);
	  break;
	case 9:
	    printf("Enter the key element to be searched:\n");
		scanf("%d",&item);
		dsearch(item,head);
		break;
	default:
	  exit (0);
	}
}
}
