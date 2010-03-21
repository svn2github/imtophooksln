Attribute VB_Name = "WMCert"
Declare Function LTMM_WMCreateCertificate Lib "wmcert.dll" (ByVal pszKey As String) As Object

' TODO: Supply your own key
Global Const WMKey$ = "ReplaceThisString"

