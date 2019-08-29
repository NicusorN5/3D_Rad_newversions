﻿using System;
using System.Windows.Forms;
using _3DRadSpaceDll;

namespace _3DRadSpace
{
#if WINDOWS || LINUX
    /// <summary>
    /// The main class.
    /// </summary>
    public static class Program
    {
        public static bool ProjectTypeScript = false;
        public static readonly string[] Version = { "1", "0", "0" }; //a char array or a int array is a better choice, but meh.
        [STAThread]
        static void Main(string[] Arguments) //Command line arguments
        {
            Environment.CurrentDirectory = Application.StartupPath;
            Application.EnableVisualStyles();
            using (var Editor = new Editor())
            {
                bool EditorOpen = true;
                if (Arguments.Length > 0)
                {
                    string extention = Arguments[0].Split('.')[1];
                    if (extention == "3drsp")
                    {
                        Editor.OpenedFile = Arguments[0];
                    }
                    else if(extention == "cs")
                    {
                        ProjectTypeScript = true;
                        EditorOpen = false;
                    }
                }
                if(EditorOpen) Editor.Run();
            }
            if(ProjectTypeScript)
            {
                ScriptW script = new ScriptW();
                script.ShowDialog();
            }
        }
    }
#endif
}