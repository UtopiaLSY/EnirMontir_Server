
// ServerDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"

#define RECVMAX_SIZE        100

typedef struct _clientinfo
{
    SOCKET sock;            //�ͻ����׽���
    bool startflag;         //��ʼ����
}CLIENTINFO, *PCLIENTINFO;

typedef struct _revpacket
{
    char name[10];
    char revdata[10];
}RECVPACKET, *PRECVPACKET;


// CServerDlg �Ի���
class CServerDlg : public CDialogEx
{
// ����
public:
	CServerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SERVER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
    CButton m_ButtOpenServer;
    CButton m_ButtConnect;
    CComboBox m_ComboClientIP;

    
private:
    CString m_EditServerPort;
    SOCKET server_sock;
    PCLIENTINFO client_infor;
    CStatic m_EditTemp;
    CStatic m_EditHum;
    CStatic m_EditCO2;
    CWinThread *listenthread;
    CWinThread *revdatathread;

public:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnBnClickedButtopen();
    afx_msg void OnBnClickedButtconnect();

public:
    static UINT ServerListen_Thread(LPVOID param);
    static UINT ServerRevData_Thread(LPVOID param);
    void ShowEnvirData(PRECVPACKET revdata);

    
    
};



