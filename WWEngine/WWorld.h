#pragma once
#include <vector>
#include <queue>
#include "Common.h"
#include "WObject.h"
#include "WCharactor.h"
class WWorld {
	struct ObjFreeHashNode {
		int idx;
		ObjFreeHashNode(int nidx) :idx(nidx){}
		bool operator < (const ObjFreeHashNode &rhs)const {
			return idx > rhs.idx;
		}
	};
	std::vector< WObject* >m_objBuf;					// �����еĶ���ָ���
	std::priority_queue< ObjFreeHashNode >m_freeque;	// ���ڲ�ѯ����ָ������Ƿ���ڱ����Ϊ�յ�λ��
public:
	WWorld();
	void AddObj(WObject *obj);							// ��һ������ָ��������ָ�����
	bool RemoveObj(int nIdx);
	bool CreateCharactor(char *szFile, char *szName, float x, float y, float z);
	void SetCamera();
	void Draw(IDirect3DDevice9*	g_pDevice);
	void Draw(IDirect3DDevice9*	g_pDevice, SkinnedMesh a, D3DMATRIX identity);
	void Init();
};