#include "WWorld.h"

WWorld::WWorld()
{
	Init();
}

void WWorld::AddObj(WObject *obj)
{
	if (m_freeque.empty()==true) {
		m_objBuf.push_back(obj);
	}
	else {
		int nfreeidx = m_freeque.top().idx;
		m_freeque.pop();
		m_objBuf[nfreeidx] = obj;
	}
}

bool WWorld::RemoveObj(int nIdx) 
{
	if (m_objBuf[nIdx] == NULL) {
		messagebox("δ�ҵ���Ҫ�Ƴ��Ķ���", "�쳣");
		return false;
	}
	m_objBuf[nIdx]->Release();
	m_objBuf[nIdx] = NULL;
	m_freeque.push(ObjFreeHashNode(nIdx));
	return true;
}

bool WWorld::CreateCharactor(char * szFile, char * szName, float x, float y, float z)
{
	WCharactor *pNewCharactor = new WCharactor(szFile, szName, x, y, z);
	AddObj(pNewCharactor);
	return false;
}

void WWorld::SetCamera()
{
	//�����������������������λ����Ϣ�����ӿڱ任��ȡ���仯��
	//Ŀǰ�ò��ַ���app.render��ʵ�֡�
}

void WWorld::Draw(IDirect3DDevice9*	g_pDevice)
{
	if (g_pDevice == NULL) {
		messagebox("�豸��ʧ");
		return;
	}
	SetCamera();
	for (unsigned i = 0; i < m_objBuf.size(); i++) {
		if (m_objBuf[i] == NULL) continue;
		m_objBuf[i]->Draw(g_pDevice);
	}
}

void WWorld::Draw(IDirect3DDevice9*	g_pDevice,SkinnedMesh a,D3DMATRIX identity)
{
	if (g_pDevice == NULL) {
		messagebox("�豸��ʧ");
		return;
	}
	a.SetPose(identity);
	a.Render(NULL);
}

void WWorld::Init()
{
	while (!m_freeque.empty())m_freeque.pop();
	for (int i = 0; i < m_objBuf.size(); i++)if (m_objBuf[i]!=NULL)m_objBuf[i]->Release();
	m_objBuf.clear();
}

