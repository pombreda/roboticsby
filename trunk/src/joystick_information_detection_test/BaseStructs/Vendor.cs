using System;

namespace Joystick_2008_To_WPF.BaseStructs
{
    class Vendor
    {
        public Guid VendorId { get; set; }

        public string VendorStr { get; set; }

        public string Name { get; set; }

        public Vendor(Guid vendorId, string vendor, string name)
        {
            VendorId = vendorId;
            VendorStr = vendor;
            Name = name;
        }
    }
}