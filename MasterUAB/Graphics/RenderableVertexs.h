#pragma once

#include <D3D11.h>

#include <assert.h>

#include "Utils.h"

class CRenderableVertexs
{
	public:
		virtual bool Render(CKGRenderManager *RenderManager, CEffect *Effect, void *Parameters)
	{
		assert(!"This method mustn't be called");
		return false;
	}
	virtual bool RenderIndexed(CKGRenderManager *RenderManager, CEffect *Effect, void *Parameters, unsigned int IndexCount=-1, unsigned int StartIndexLocation=0, unsigned int BaseVertexLocation=0)
	{
		assert(!"This method mustn't be called");
		return false;
	}
};