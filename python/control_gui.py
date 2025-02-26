import tkinter as tk
from tkinter import ttk, messagebox
import serial
import 

class SerialButtonApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Serial Port Controller")
        
        # Initialize serial port
        try:
            self.ser = serial.Serial(
                port='/dev/ttyUSB0',
                baudrate=9600,
                parity=serial.PARITY_NONE,
                stopbits=serial.STOPBITS_ONE,
                bytesize=serial.EIGHTBITS,
                timeout=1
            )
        except:
            messagebox.showerror("Serial Error", f"Failed to open serial port:\n")
            self.root.destroy()
            return

        # Create GUI elements
        self.create_widgets()
        
        # Handle window closing
        self.root.protocol("WM_DELETE_WINDOW", self.on_close)

    def create_widgets(self):
        # Frame for buttons
        button_frame = ttk.Frame(self.root, padding="20")
        button_frame.pack()

        # Buttons
        self.btn1 = ttk.Button(button_frame, text="Inner Left", command=lambda: self.send_data('A'))
        self.btn1.grid(row=0, column=0, padx=5, pady=5)

        self.btn2 = ttk.Button(button_frame, text="Inner Right ", command=lambda: self.send_data('B'))
        self.btn2.grid(row=0, column=1, padx=5, pady=5)

        self.btn3 = ttk.Button(button_frame, text="Outer Left", command=lambda: self.send_data('C'))
        self.btn3.grid(row=1, column=0, padx=5, pady=5)

        self.btn4 = ttk.Button(button_frame, text="Outer Right", command=lambda: self.send_data('D'))
        self.btn4.grid(row=1, column=1, padx=5, pady=5)

        # Status label
        self.status_label = ttk.Label(self.root, text="Ready")
        self.status_label.pack(pady=10)

    def send_data(self, char):
        try:
            if self.ser.is_open:
                self.ser.write(bytearray(char,'ascii'))
                print('Written:', char)
                self.status_label.config(text=f"Sent: {char}")
            else:
                messagebox.showerror("Error", "Serial port is not open!")
        except Exception as e:
            messagebox.showerror("Error", f"Failed to send data:\n{str(e)}")

    def on_close(self):
        if hasattr(self, 'ser') and self.ser.is_open:
            self.ser.close()
        self.root.destroy()

if __name__ == "__main__":
    root = tk.Tk()
    app = SerialButtonApp(root)
    root.mainloop()
    