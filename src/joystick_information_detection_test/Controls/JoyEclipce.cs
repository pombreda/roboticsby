using System;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Shapes;
using System.Windows;

namespace Joystick_2008_To_WPF.Controls
{

    public class JoyEclipce : Canvas
    {
        private readonly Ellipse _ell;
        private SolidColorBrush _ellColor;
        public JoyEclipce()
        {
            _ell = new Ellipse { Width = 30, Height = 30, Stroke = new SolidColorBrush(Colors.Black) };
            SetLeft(_ell, 404);
            SetTop(_ell, 125);
            Children.Add(_ell);
        }
        public void UpdateColor(SolidColorBrush colorBrush)
        {
            _ellColor = colorBrush;
            Dispatcher.Invoke(
            new Action(() =>
            {
                var el = (Ellipse)Children[0];
                el.Fill = _ellColor;
            }
                )
            );
        }

        public void UpdateEllipcePosition(int x, int y)
        {
            Dispatcher.Invoke(
            new Action(() =>
            {
                var el = (Ellipse)Children[0];
                el.Margin = new Thickness(x / 395 * 2, y / 395 * 2, 0, 0);
            }
                )
            );
        }
    }
}
