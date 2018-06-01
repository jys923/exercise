#pragma once

typedef void(*vpCallBackFunction)(void);                  // 콜백함수 함수포인터로정의

vpCallBackFunction  m_pCBFunction;                             // 콜백함수 생성
void SetCallBackFuntion(vpCallBackFunction cbFunction);
void ExecutionCallBack(void);

inline void SetCallBackFuntion(vpCallBackFunction cbFunction)
{
	m_pCBFunction = cbFunction;                             // 콜백함수로 함수 대입
}

inline void ExecutionCallBack(void)
{
	if (m_pCBFunction)
		m_pCBFunction();                                   // 콜백함수 호출

}
//[출처] 함수포인터와 콜백함수 | 작성자 은빛파도