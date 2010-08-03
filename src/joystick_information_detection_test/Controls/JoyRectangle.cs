using System.Windows.Controls;
using System.Windows.Shapes;
using System.Windows.Media;
using System;

namespace Joystick_2008_To_WPF.Controls
{
    public class JoyRectangle : Canvas
    {
        private readonly Rectangle _rectangle;
        public JoyRectangle()
        {
            _rectangle = new Rectangle
                             {
                                 Height = 24,
                                 Width = 10,
                                 Opacity = 0.95,
                                 Stroke = new SolidColorBrush(Colors.Black)
                             };
            SetLeft(_rectangle, 404);
            SetTop(_rectangle, 516);
            _rectangle.Fill = new SolidColorBrush(Color.FromRgb(0, 230, 0));
            Children.Add(_rectangle);
        }
        public void UpdateRectanglePosition(int x)
        {
            Dispatcher.Invoke(
                new Action(() =>
                {
                    var rec = (Rectangle)Children[0];
                    rec.Width = x / 395 * 2;
                }
                    )
                );
        }
        public void UpdateColor(int x, int max)
        {            
            Dispatcher.Invoke(
            new Action(() =>
            {
                var rectangle = (Rectangle)Children[0];//Convert.ToByte(200 * x / max)
                rectangle.Fill = new SolidColorBrush(Color.FromRgb(255, Convert.ToByte(255 - 254 * x / max), 0));
            }
                )
            );
        }
    }
}
