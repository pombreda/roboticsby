using System;

namespace Joystick_2008_To_WPF.BaseStructs
{
    class Product
    {
        public Guid ProductId { get; set; }

        public string ProductStr { get; set; }

        public Guid VendorId { get; set; }

        public string Name { get; set; }

        public Product(Guid productId, string product, string name, Guid vendorId)
        {
            ProductId = productId;
            ProductStr = product;
            VendorId = vendorId;
            Name = name;
        }
    }
}