#pragma once

typedef void(*vpCallBackFunction)(void);                  // �ݹ��Լ� �Լ������ͷ�����

vpCallBackFunction  m_pCBFunction;                             // �ݹ��Լ� ����
void SetCallBackFuntion(vpCallBackFunction cbFunction);
void ExecutionCallBack(void);

inline void SetCallBackFuntion(vpCallBackFunction cbFunction)
{
	m_pCBFunction = cbFunction;                             // �ݹ��Լ��� �Լ� ����
}

inline void ExecutionCallBack(void)
{
	if (m_pCBFunction)
		m_pCBFunction();                                   // �ݹ��Լ� ȣ��

}
//[��ó] �Լ������Ϳ� �ݹ��Լ� | �ۼ��� �����ĵ�