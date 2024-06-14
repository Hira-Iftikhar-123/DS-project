**Laptop Inventory Management System**
**Overview:**

The Laptop Inventory Management System is a C++ application designed to manage an inventory of laptops. It includes functionalities for adding, searching, and managing laptops with attributes such as ISBN, quantity, price, color, brand, storage capacity, screen size, camera resolution, and battery life. The system also handles user reviews for each laptop and uses AVL trees to maintain balance for efficient searching and sorting.

**Features:**
Add New Laptops: Insert new laptop entries into the inventory with details like ISBN, quantity, price, etc.
Search Laptops: Search for laptops by various attributes.
Manage Inventory: Update quantities, prices, and other details of existing laptops.
User Reviews: Add and manage user reviews for each laptop.
Balanced Tree Structure: Uses AVL trees for efficient data management.

**Classes and Structures:**

**1. Laptop:**
This class represents a laptop with the following attributes:

ISBN: A unique identifier for the laptop.
quantity: The number of units available.
price: The price of the laptop.
year: The manufacturing year.
color: The color of the laptop.
brand: The brand of the laptop.
storageCapacity: The storage capacity of the laptop.
screenSize: The screen size of the laptop.
cameraResolution: The camera resolution.
batteryLife: The battery life.
reviews: A stack of user reviews.

**2. Inventory**
Handles the collection of laptops and includes methods for adding, searching, and managing laptops.

**3. AVL**
Implements an AVL tree to maintain a balanced structure for the inventory, providing efficient insertion, deletion, and search operations.

**4. User**
Represents a user interacting with the system, allowing operations such as adding laptops to the inventory and submitting reviews.


**Clone the repository:**
git clone https://github.com/yourusername/laptop-inventory.git

**Navigate to the project directory:**
cd laptop-inventory

**Compile the project:**
g++ -o mainproject mainproject.cpp

**Usage:**
Run the compiled program:
./mainproject
Follow the on-screen instructions to interact with the inventory system.

**Contributing:**
Contributions are welcome! Please fork the repository and submit a pull request.
