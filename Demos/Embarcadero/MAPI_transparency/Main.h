/*****************************************************************************
 * ==> Transparency demo ----------------------------------------------------*
 *****************************************************************************
 * Description : A transparency effect, press the left/right arrow keys to   *
 *               increase or decrease the rotation speed, press the up/down  *
 *               arrow keys to increase or decrease the transparency         *
 * Developer   : Jean-Milost Reymond                                         *
 * Copyright   : 2015 - 2018, this file is part of the Minimal API. You are  *
 *               free to copy or redistribute this file, modify it, or use   *
 *               it for your own projects, commercial or not. This file is   *
 *               provided "as is", without ANY WARRANTY OF ANY KIND          *
 *****************************************************************************/

#ifndef MainH
#define MainH

// vcl
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

// mini API
#include "MiniCommon.h"
#include "MiniGeometry.h"
#include "MiniVertex.h"
#include "MiniShapes.h"
#include "MiniShader.h"
#include "MiniRenderer.h"

/**
* Main form
*@author
*/
class TMainForm : public TForm
{
    __published:
        void __fastcall FormShow(TObject* pSender);
        void __fastcall FormResize(TObject* pSender);
        void __fastcall FormPaint(TObject* pSender);
        void __fastcall FormKeyDown(TObject* pSender, WORD& key, TShiftState shift);

    public:
        /**
        * Constructor
        *@param pOwner - form owner
        */
        __fastcall TMainForm(TComponent* pOwner);

        /**
        * Destructor
        */
        virtual __fastcall ~TMainForm();

    private:
        HDC               m_hDC;
        HGLRC             m_hRC;
        MINI_Shader       m_Shader;
        GLuint            m_ShaderProgram;
        float*            m_pSphereVB;
        unsigned          m_SphereVertexCount;
        MINI_Index*       m_pSphereIndexes;
        unsigned          m_SphereIndexCount;
        float*            m_pSurfaceVB;
        unsigned          m_SurfaceVertexCount;
        const float       m_SurfaceWidth;
        const float       m_SurfaceHeight;
        const float       m_SphereRadius;
        float             m_Angle;
        float             m_RotationSpeed;
        float             m_AlphaLevel;
        GLuint            m_GlassTextureIndex;
        GLuint            m_CloudTextureIndex;
        GLuint            m_TexSamplerSlot;
        GLuint            m_AlphaSlot;
        GLuint            m_ModelviewUniform;
        MINI_VertexFormat m_VertexFormat;
        unsigned __int64  m_PreviousTime;

        /**
        * Enables OpenGL
        *@param hWnd - Windows handle
        *@param hDC - device context
        *@param hRC - OpenGL rendering context
        */
        void EnableOpenGL(HWND hWnd, HDC* hDC, HGLRC* hRC);

        /**
        * Disables OpenGL
        *@param hWnd - Windows handle
        *@param hDC - device context
        *@param hRC - OpenGL rendering context
        */
        void DisableOpenGL(HWND hWnd, HDC hDC, HGLRC hRC);

        /**
        * Creates the viewport
        *@param w - viewport width
        *@param h - viewport height
        */
        void CreateViewport(float w, float h);

        /**
        * Initializes the scene
        *@param w - scene width
        *@param h - scene height
        */
        void InitScene(int w, int h);

        /**
        * Deletes the scene
        */
        void DeleteScene();

        /**
        * Updates the scene
        *@param elapsedTime - elapsed time since last update, in milliseconds
        */
        void UpdateScene(float elapsedTime);

        /**
        * Draws the scene
        */
        void DrawScene();

        /**
        * Called while application is idle
        *@param pSender - event sender
        *@param[in, out] done - if true, event is done and will no longer be called
        */
        void __fastcall OnIdle(TObject* pSender, bool& done);
};
extern PACKAGE TMainForm* MainForm;
#endif
