import sys
print(sys.path)

import hid

def list_hid_devices():
    # Get a list of connected HID devices
    devices = hid.enumerate()

    if not devices:
        print("No HID devices found.")
        return

    print("List of HID devices:")
    for device_info in devices:
        print("\nVendor ID: {}\nProduct ID: {}\nSerial Number: {}\nManufacturer: {}\nProduct: {}\n"
              .format(device_info['vendor_id'], device_info['product_id'],
                      device_info['serial_number'], device_info['manufacturer_string'],
                      device_info['product_string']))

if __name__ == "__main__":
    list_hid_devices()