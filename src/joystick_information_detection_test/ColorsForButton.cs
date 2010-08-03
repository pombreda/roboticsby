using System;
using System.Windows.Media;

namespace Joystick_2008_To_WPF
{
    class ColorsForButton
    {
        public static SolidColorBrush GenerateColour(string buttons)
        {
            var newColor = new SolidColorBrush(Colors.Red);
            if (buttons != "")
            {                
                int green = 0;
                int red = 0;
                int blue = 0; 
                Color c;
                string[] buts = buttons.Split(' ');
                for (int i = 0; i < buts.Length-1; i++)
                {
                    byte but = Convert.ToByte(buts[i]);
                    if ((but < 20) && (but > 0))
                    {                        
                        #region SWITCH
                        switch (but)
                        {                             
                            case 0:
                                c = Colors.White;
                                blue += Convert.ToInt32(c.B);
                                green += Convert.ToInt32(c.G);
                                red += Convert.ToInt32(c.R);
                                break;
                            case 1:
                                c = Colors.White;
                                blue += Convert.ToInt32(c.B);
                                green += Convert.ToInt32(c.G);
                                red += Convert.ToInt32(c.R);
                                break;
                            case 2:
                                c = Colors.Yellow;
                                blue += Convert.ToInt32(c.B);
                                green += Convert.ToInt32(c.G);
                                red += Convert.ToInt32(c.R);
                                break;
                            case 3:
                                c = Colors.Red;
                                blue += Convert.ToInt32(c.B);
                                green += Convert.ToInt32(c.G);
                                red += Convert.ToInt32(c.R);
                                break;
                            case 4:
                                c = Colors.Navy;
                                blue += Convert.ToInt32(c.B);
                                green += Convert.ToInt32(c.G);
                                red += Convert.ToInt32(c.R);
                                break;
                            case 5:
                                c = Colors.RoyalBlue;
                                blue += Convert.ToInt32(c.B);
                                green += Convert.ToInt32(c.G);
                                red += Convert.ToInt32(c.R);
                                break;
                            case 6:
                                c = Colors.Black;
                                blue += Convert.ToInt32(c.B);
                                green += Convert.ToInt32(c.G);
                                red += Convert.ToInt32(c.R);
                                break;
                            case 7:
                                c = Colors.Brown;
                                blue += Convert.ToInt32(c.B);
                                green += Convert.ToInt32(c.G);
                                red += Convert.ToInt32(c.R);
                                break;
                            case 8:
                                c = Colors.LimeGreen;
                                blue += Convert.ToInt32(c.B);
                                green += Convert.ToInt32(c.G);
                                red += Convert.ToInt32(c.R);
                                break;
                            case 9:
                                c = Colors.Orange;
                                blue += Convert.ToInt32(c.B);
                                green += Convert.ToInt32(c.G);
                                red += Convert.ToInt32(c.R);
                                break;
                            case 10:
                                c = Colors.ForestGreen;
                                blue += Convert.ToInt32(c.B);
                                green += Convert.ToInt32(c.G);
                                red += Convert.ToInt32(c.R);
                                break;
                            case 11:
                                c = Colors.Cyan;
                                blue += Convert.ToInt32(c.B);
                                green += Convert.ToInt32(c.G);
                                red += Convert.ToInt32(c.R);
                                break;
                            case 12:
                                c = Colors.BurlyWood;
                                blue += Convert.ToInt32(c.B);
                                green += Convert.ToInt32(c.G);
                                red += Convert.ToInt32(c.R);
                                break;
                            case 13:
                                c = Colors.Aqua;
                                blue += Convert.ToInt32(c.B);
                                green += Convert.ToInt32(c.G);
                                red += Convert.ToInt32(c.R);
                                break;
                            case 14:
                                c = Colors.Black;
                                blue += Convert.ToInt32(c.B);
                                green += Convert.ToInt32(c.G);
                                red += Convert.ToInt32(c.R);
                                break;
                            case 15:
                                c = Colors.Coral;
                                blue += Convert.ToInt32(c.B);
                                green += Convert.ToInt32(c.G);
                                red += Convert.ToInt32(c.R);
                                break;
                            case 16:
                                c = Colors.DeepSkyBlue;
                                blue += Convert.ToInt32(c.B);
                                green += Convert.ToInt32(c.G);
                                red += Convert.ToInt32(c.R);
                                break;
                            case 17:
                                c = Colors.Orange;
                                blue += Convert.ToInt32(c.B);
                                green += Convert.ToInt32(c.G);
                                red += Convert.ToInt32(c.R);
                                break;
                            case 18:
                                c = Colors.RoyalBlue;
                                blue += Convert.ToInt32(c.B);
                                green += Convert.ToInt32(c.G);
                                red += Convert.ToInt32(c.R);
                                break;
                            case 19:
                                c = Colors.WhiteSmoke;
                                blue += Convert.ToInt32(c.B);
                                green += Convert.ToInt32(c.G);
                                red += Convert.ToInt32(c.R);
                                break;
                            case 20:
                                c = Colors.Orchid;
                                blue += Convert.ToInt32(c.B);
                                green += Convert.ToInt32(c.G);
                                red += Convert.ToInt32(c.R);
                                break;
                        }
                        #endregion
                    }
                    if (but <= 0)
                    {
                        c = Colors.White;
                        blue += Convert.ToInt32(c.B);
                        green += Convert.ToInt32(c.G);
                        red += Convert.ToInt32(c.R);
                    }
                    if (but > 20)
                    {
                        c = Colors.Red;
                        blue += Convert.ToInt32(c.B);
                        green += Convert.ToInt32(c.G);
                        red += Convert.ToInt32(c.R);
                    }
                }
                byte ansRed = Convert.ToByte(red / (buts.Length-1));
                byte ansGreen = Convert.ToByte(green / (buts.Length - 1));
                byte ansBlue = Convert.ToByte(blue / (buts.Length - 1));
                var br = new SolidColorBrush(Color.FromRgb(ansRed, ansGreen, ansBlue));
                return br;
            }
            return newColor;
        }
    }
}
