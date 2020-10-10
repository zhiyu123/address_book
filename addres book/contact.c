#include"contact.h"

int find_person(const Contact* pcon, char* name)				//Ѱ�Ҹ��庯��
{
	assert(pcon != NULL);
	int i = 0;
	for (i = 0; i < pcon->size; i++)
	{
		if (strcmp(pcon->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void search(const Contact* pcon)
{
	assert(pcon != NULL);
	char name[MAX_NAME] = { 0 };
	int flag = 0;
	printf("������Ҫ�����˵�������");
	scanf("%s", name);
	flag = find_person(pcon, name);
	if (flag == -1)
	{
		printf("���޴��ˣ�\n");
	}
	else
	{
		printf("%-10s\t%-10s\t%-10s\t%-20s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		printf("%-10s\t", pcon->data[flag].name);
		printf("%-10s\t", pcon->data[flag].sex);
		printf("%-10d\t", pcon->data[flag].age);
		printf("%-20s\t", pcon->data[flag].phone);
		printf("%-20s\t", pcon->data[flag].addr);
		printf("\n");
	}
}

void init_contact(Contact* pcon)			//��ʼ���ṹ�庯��
{
	assert(pcon != NULL);
	pcon->size = 0;
	memset(pcon->data, 0, sizeof(pcon->data));
}

void add(Contact* pcon)					//��Ӻ���
{
	assert(pcon != NULL);
	if (pcon->size == MAX_PERSON)
	{
		printf("ͨѶ¼�������޷���ӣ�\n");
	}
	else
	{
		printf("������Ҫ����˵�������");
		scanf("%s", pcon->data[pcon->size].name);
		printf("������Ҫ����˵��Ա�");
		scanf("%s", pcon->data[pcon->size].sex);
		printf("������Ҫ����˵����䣺");
		scanf("%d", &(pcon->data[pcon->size].age));
		printf("������Ҫ����˵ĵ绰��");
		scanf("%s", pcon->data[pcon->size].phone);
		printf("������Ҫ����˵ĵ�ַ��");
		scanf("%s", pcon->data[pcon->size].addr);
		pcon->size++;
		printf("�����ɣ�\n");
	}
}

void show(const Contact* pcon)				//��ʾ����
{
	assert(pcon != NULL);
	int i = 0;
	printf("%-10s\t%-10s\t%-10s\t%-20s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	for (i = 0; i < pcon->size; i++)
	{
		printf("%-10s\t", pcon->data[i].name);
		printf("%-10s\t", pcon->data[i].sex);
		printf("%-10d\t", pcon->data[i].age);
		printf("%-20s\t", pcon->data[i].phone);
		printf("%-20s\t", pcon->data[i].addr);
		printf("\n");
	}
}

void delete(Contact* pcon)
{
	assert(pcon != NULL);
	char name[MAX_NAME] = { 0 };
	int i = 0;
	int pos = 0;
	if (pcon->size == 0)
	{
		printf("��ǰͨѶ¼Ϊ�գ�\n");
	}
	else
	{
		printf("������Ҫɾ���˵�������");
		scanf("%s", name);
		pos = find_person(pcon, name);
		for (i = pos; i < pcon->size - 1; i++)
		{
			pcon->data[pos] = pcon->data[pos + 1];
		}
		pcon->size--;
		printf("ɾ���ɹ���\n");
	}
}

void modify(Contact* pcon)
{
	assert(pcon != NULL);
	char name[MAX_NAME] = { 0 };
	int input = 0;
	int flag = 0;
	char m_name[MAX_NAME] = { 0 };
	char m_sex[MAX_SEX] = { 0 };
	int m_age = 0;
	char m_phone[MAX_PHONE] = { 0 };
	char m_addr[MAX_ADDR] = { 0 };
	printf("������Ҫ�޸��˵����֣�");
	scanf("%s", name);
	flag = find_person(pcon, name);
	if (flag == -1)
	{
		printf("���޴��ˣ�\n");
	}
	else
	{
		printf("%-10s\t%-10s\t%-10s\t%-20s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		printf("%-10s\t", pcon->data[flag].name);
		printf("%-10s\t", pcon->data[flag].sex);
		printf("%-10d\t", pcon->data[flag].age);
		printf("%-20s\t", pcon->data[flag].phone);
		printf("%-20s\t", pcon->data[flag].addr);
		printf("\n");
		while (1)
		{
			printf("��ѡ��Ҫ�ı����Ϣ(1.name\t2.sex\t3.age\t4.phone\t5.addr)��");
			scanf("%d", &input);
			if (input == 1)
			{
				printf("�������޸ĺ�����֣�");
				scanf("%s", m_name);
				strcpy(pcon->data[flag].name, m_name);
				break;
			}
			else if (input == 2)
			{
				printf("�������޸ĺ���Ա�");
				scanf("%s", m_sex);
				strcpy(pcon->data[flag].sex, m_sex);
				break;
			}
			else if (input == 3)
			{
				printf("�������޸ĺ�����䣺");
				scanf("%d", &m_age);
				pcon->data[flag].age = m_age;
				break;
			}
			else if (input == 4)
			{
				printf("�������޸ĺ�ĵ绰��");
				scanf("%s", m_phone);
				strcpy(pcon->data[flag].phone, m_phone);
				break;
			}
			else if (input == 5)
			{
				printf("�������޸ĺ�ĵ�ַ��");
				scanf("%s", m_addr);
				strcpy(pcon->data[flag].addr, m_addr);
				break;
			}
			else
				printf("����������������룡\n");
		}
		printf("�޸ĳɹ���\n");
	}
}

void empty(Contact* pcon)
{
	assert(pcon != NULL);
	int choose = 0;
	printf("��ȷ��Ҫ���������?(1.Yes 2.No):");
	scanf("%d", &choose);
	if (choose == 2)
	{
		printf("���ʧ�ܣ�\n");
	}
	else if (choose == 1)
	{
		pcon->size = 0;
		printf("��ճɹ���\n");
	}
}

void sort(Contact* pcon)			//����
{
	assert(pcon != NULL);
	int i = 0;
	int j = 0;
	for (i = 0; i < pcon->size - 1; i++)
	{
		for (j = 0; j < pcon->size - 1 - i; j++)
		{
			if (pcon->data[j].age > pcon->data[j + 1].age)
			{
				pcon->data[MAX_PERSON - 1] = pcon->data[j];
				pcon->data[j] = pcon->data[j + 1];
				pcon->data[j + 1] = pcon->data[MAX_PERSON - 1];
			}
		}
	}
	printf("��������������ɣ�\n");
}
