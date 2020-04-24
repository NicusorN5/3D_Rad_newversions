﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Content;
using System.IO;

namespace _3DRadSpaceDll
{
    /// <summary>
    /// Represents an Skybox object.
    /// </summary>
    public class Skybox : GameObject,IDisposable
    {
        /// <summary>
        /// Empty constructor.
        /// </summary>
        public Skybox()
        {
            _size = 400f;
            Name = "Skybox";
            Enabled = false;
        }
        /// <summary>
        /// Main skybox constructor.
        /// </summary>
        /// <param name="name"></param>
        /// <param name="enabled"></param>
        /// <param name="path"></param>
        public Skybox(string name,bool enabled,string path)
        {
            Name = name;
            Enabled = enabled;
            Resource = path;
        }
        /// <summary>
        /// Size of the cube itself.
        /// </summary>
        public float Size
        {
            get
            {
                return _size;
            }
            set
            {
                _size = value;
                if (Size <= 0) throw new ArgumentException("Size cannot be smaller than or equal to 0.");
            }
        }
        /// <summary>
        /// Loads the skybox.
        /// </summary>
        /// <param name="content"></param>
        /// <param name="gd">GraphicsDevice used to initialize the texture.</param>
        public void Load(ContentManager content, GraphicsDevice gd)
        {
            if (_skyBoxCube == null) _skyBoxCube = content.Load<Model>("Skybox\\skybox");
            //if(_shader == null) _shader = content.Load<Effect>("Shaders\\SH_Skybox");

            FileStream str = new FileStream(Resource, FileMode.Open);
            Texture = Texture2D.FromStream(gd, str);
            str.Close();
            str.Dispose();

            LinkAvalableCamera();

            base.Load(content);
        }
        float _size;
        Camera _linkedc;
        static Model _skyBoxCube;
        /// <summary>
        /// A entire image representing the skybox.
        /// </summary>
        public Texture2D Texture;
        static Effect _shader; //right, who tf needs multiple skyboxes, lmfao
        /// <summary>
        /// Draws the skybox.
        /// </summary>
        /// <param name="spriteBatch"></param>
        /// <param name="view"></param>
        /// <param name="projection"></param>
        public override void Draw(SpriteBatch spriteBatch, Matrix? view, Matrix? projection)
        {
            if (_linkedc == null) LinkAvalableCamera(); //We determine a avalable Camera object 
            //Guarantee that the cube is made from a single textured mesh. Unless some smartass comes to modify the default assets.
            foreach (BasicEffect effect in _skyBoxCube.Meshes[0].Effects)
            {
                effect.World = Matrix.CreateScale(_size) * Matrix.CreateTranslation(Position);
                effect.View = view.Value;
                effect.Projection = projection.Value;
                effect.TextureEnabled = true;
                effect.Texture = Texture;
                effect.DiffuseColor = new Vector3(1, 1, 1); // please make the skybox look more colorful, PLIZ - 1:53 AM update : thank you, you saved my sanity
            }
            _skyBoxCube.Meshes[0].Draw();
            base.Draw(spriteBatch, view, projection);
        }
        /// <summary>
        /// Draws the skybox in the editor - an extra argument is needed.
        /// </summary>
        /// <param name="editor_cam_pos"></param>
        /// <param name="view"></param>
        /// <param name="projection"></param>
        public void EditorDraw(Vector3 editor_cam_pos, Matrix view, Matrix projection)
        {
            //Guarantee that the cube is made from a single textured mesh. Unless some smartass comes to modify the default assets.
            foreach (BasicEffect effect in _skyBoxCube.Meshes[0].Effects)
            {
                effect.World = Matrix.CreateScale(_size) * Matrix.CreateTranslation(editor_cam_pos-new Vector3(0.5f,0.5f,0.5f));
                effect.View = view;
                effect.Projection = projection;
                effect.TextureEnabled = true;
                effect.Texture = Texture;
                effect.DiffuseColor = new Vector3(1, 1, 1); // please make the skybox look more colorful, PLIZ - 1:53 AM update : thank you, you saved my sanity
            }
            _skyBoxCube.Meshes[0].Draw();

            //using the older shader
            /*
            foreach (ModelMesh mesh in _skyBoxCube.Meshes)
            {
                foreach (ModelMeshPart part in mesh.MeshParts)
                {
                    Matrix w = Matrix.CreateScale(_size) * Matrix.CreateTranslation(editor_cam_pos);
                    part.Effect = _shader;
                    _shader.Parameters["View"].SetValue(view);
                    _shader.Parameters["Projection"].SetValue(projection);
                    _shader.Parameters["World"].SetValue(w);
                    _shader.Parameters["ModelTexture"].SetValue(Texture);
                }
                mesh.Draw();
            }
            */
            base.EditorDraw(null, null, null);
        }
        /// <summary>
        /// Finds a camera object to link the skybox to.
        /// </summary>
        public void LinkAvalableCamera()
        {
            for (int i = 0; i < Game.GameObjects.Count; i++)
            {
                if (Game.GameObjects[i] is Camera c)
                {
                    if (c.Enabled)
                    {
                        _size = c.MaxDrawDist - 1;
                        _linkedc = c;
                    }
                }
            }
        }
        /// <summary>
        /// Frees the loaded texture.
        /// </summary>
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
        bool _disposed = false;
        /// <summary>
        /// Protected Dispose().
        /// </summary>
        /// <param name="disposing"></param>
        protected void Dispose(bool disposing)
        {
            if (_disposed) return;
            if (disposing)
            {
                Texture.Dispose();
            }
            _disposed = true;
        }
    }
}