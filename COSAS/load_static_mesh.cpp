void CStaticMesh::Load()
{
	FILE *l_File=NULL;
	fopen_s(, &l_File);
	
	fread(&l_Header, sizeof(unsigned short), 1, l_File);
	
	//read materials
	
	
	unsigned int m_NumIndexs=0;
	for(materials)
	{
	void *l_VtxsData=NULL;
	void *l_IdxData=NULL;
	
	unsigned short l_VertexType;
	fread(&l_VertexType, sizeof(unsigned short), 1, l_File);
	
	if(l_VertexType==MV_POSITION_NORMAL_TEXTURE_VERTEX::GetVertexType())
		l_NumBytes=sizeof(MV_POSITION_NORMAL_TEXTURE_VERTEX)*l_NumVertexs;
	else if(l_VertexType==MV_POSITION_COLOR_VERTEX::GetVertexType())
		l_NumBytes=sizeof(MV_POSITION_COLOR_VERTEX)*l_NumVertexs;
	else if(l_VertexType==MV_POSITION_TEXTURE_VERTEX::GetVertexType())
		l_NumBytes=sizeof(MV_POSITION_TEXTURE_VERTEX)*l_NumVertexs;
	else if(l_VertexType==MV_POSITION_COLOR_TEXTURE_VERTEX::GetVertexType())
		l_NumBytes=sizeof(MV_POSITION_COLOR_TEXTURE_VERTEX)*l_NumVertexs;

	l_VtxsData=malloc(l_NumBytes);
	fread(&l_VtxsData, 1, l_NumBytes, l_File);
	
	unsigned short l_IndexType;
	fread(&l_IndexType, sizeof(unsigned short), 1, l_File);
	
	if(l_IndexType==16)
	{
		unsigned short l_NumIndexsFile;
		fread(&l_NumIndexsFile, sizeof(unsigned short), 1, l_File);
		l_NumBytes=sizeof(unsigned short)*l_NumIndexsFile;
		m_NumIndexs=(unsigned int)l_NumIndexsFile;
	}
	else if(l_IndexType==32)
	{
		unsigned int l_NumIndexsFile;
		fread(&l_NumIndexsFile, sizeof(unsigned int), 1, l_File);
		l_NumBytes=sizeof(unsigned int)*l_NumIndexsFile;
		m_NumIndexs=l_NumIndexsFile;
	}
	else
		trace

	
	l_IdxData=malloc(l_NumBytes);
	fread(&l_IdxData, 1, l_NumBytes, l_File);
	
	CRenderableVertexs *l_RV=NULL;
	
	if(l_VertexType==MV_POSITION_NORMAL_TEXTURE_VERTEX::GetVertexType())
	{
		if(l_IndexType==16)
			l_RV=new CUABTriangleListRenderableIndexed16Vertexs<MV_POSITION_NORMAL_TEXTURE_VERTEX>(l_VtxsData, l_NumVertexs, l_IdxData, l_NumIndexsFile);
		else
			l_RV=new CUABTriangleListRenderableIndexed32Vertexs<MV_POSITION_NORMAL_TEXTURE_VERTEX>(l_VtxsData, l_NumVertexs, l_IdxData, l_NumIndexsFile);
	}
	else if(l_VertexType==MV_POSITION_NORMAL_TEXTURE_VERTEX::GetVertexType())
	{
		if(l_IndexType==16)
			l_RV=new CUABTriangleListRenderableIndexed16Vertexs<MV_POSITION_NORMAL_TEXTURE_VERTEX>(l_VtxsData, l_NumVertexs, l_IdxData, l_NumIndexsFile);
		else
			l_RV=new CUABTriangleListRenderableIndexed32Vertexs<MV_POSITION_NORMAL_TEXTURE_VERTEX>(l_VtxsData, l_NumVertexs, l_IdxData, l_NumIndexsFile);
	}
	
	
	m_RenderableVertexs.push_back(l_RV);
	
	
	
	
	free(l_VtxsData);
	free(l_IdxData);
	}
	
	fread(&l_Footer, sizeof(unsigned short), 1, l_File);
	
	
	
	
	fclose(l_File);
}
