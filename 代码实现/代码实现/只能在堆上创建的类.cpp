/*
class   NoStackObject
{
protected://���캯������Ϊ��������˽��
	NoStackObject() {   }
	~NoStackObject() {   }
public:
	static   NoStackObject*   creatInstance()//�����Ǿ�̬��Ա��������Ϊ��̬��Ա�������Բ�ͨ���������ʣ�����ͨ�����������������
	{
		return   new   NoStackObject();//���ñ����Ĺ��캯��   
	}
	void   destroy()
	{
		delete   this;//���ñ�������������   
	}
};

NoStackObject*   hash_ptr = NoStackObject::creatInstance();
//��hash_ptrָ��Ķ�����в���   
hash_ptr->destroy();
hash_ptr = NULL;   //��ֹʹ������ָ��
*/

//�����Ѷ����Ψһ������ʹ��new, ��ֹʹ��new�Ϳɽ�ֹ�����Ѷ���. ����newִ��ʱ�����operator new, ��operator new�ǿ����ص�, ���Խ�operator new��operator delete����Ϊprivate����. ����ջ������Ҫ����new, ��Ϊ����ջ������Ҫ�����ڴ�, ����ֱ�ӵ�����ջָ�뽫����ѹջ, ��operator new����Ҫ�������������ʵĶ��ڴ�, Ϊ�Ѷ������ռ�.