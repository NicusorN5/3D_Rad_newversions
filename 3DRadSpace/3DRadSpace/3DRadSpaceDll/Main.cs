﻿using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3DRadSpaceDll
{
    /// <summary>
    /// Main class, containing glogbal variables.
    /// </summary>
    public static class Main
    {
        public static List<Object> Objects = new List<object>();
        public static bool TryExit;
        public static CultureInfo Culture = CultureInfo.InvariantCulture;
    }
}
