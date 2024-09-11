/*
* Name: Carlos Aldaco Flores, 5008406281, 1006, 2
* Description: This program that helps its users create, find, and
* update local community resources such as food banks, 
* Input: Integers representing the choice to either create, find,
* or update community resources
* Output: A creation success message, a list of resources, update
* success message, or an error message.
*/

#include <iostream>
#include <string>
#include <vector>

/*
* class_identifier: Class representing a community reasource
*
* constructors:     CommunityResource(std::string n, std::string t, 
*                   std::string a, std::string c);
*
* public functions: void setName(std::string n);
*                   void setType(std::string t);
*                   void setAddress(std::string a);
*                   void setContact(std::string c);
*                   std::string getName() const;
*                   std::string getType() const;
*                   std::string getAddress() const;
*                   std::string getContact() const;
*                   void displayResource() const;
*
* static members:   std::string getName() const;
*                   std::string getType() const;
*                   std::string getAddress() const;
*                   std::string getContact() const;
*                   void displayResource() const;
*/
class CommunityResource
{
private:
std::string name;          // Name of resource
std::string type;          // Type of resource
std::string address;       // Physical location
std::string contact;       // Contact information like number or email

public:
// Constructor
CommunityResource(std::string n, std::string t, std::string a, 
   std::string c);

// Accessor Functions (Getters)
std::string getName() const;
std::string getType() const;
std::string getAddress() const;
std::string getContact() const;

// Mutator Functions (Setters)
void setName(std::string n);
void setType(std::string t);
void setAddress(std::string a);
void setContact(std::string c);

// Display Function
void displayResource() const;
};

// Function prototypes for menu options
void addResource(std::vector<CommunityResource>& resources);
void viewResources(const std::vector<CommunityResource>& resources);
void updateResource(std::vector<CommunityResource>& resources);
void updateDetails(CommunityResource& resource);
bool resourceExists(const std::string name, 
   std::vector<CommunityResource>& resources);

int main()
{
   // Vector to hold list of resources
   std::vector<CommunityResource> resources;    

   // Store choice for desired task
   int choice;
   do
   {
   std::cout << "Community Resource Database\n";
   std::cout << "1. Add Resource\n";
   std::cout << "2. View Resources\n";
   std::cout << "3. Update Resource\n";
   std::cout << "4. Exit\n";
   std::cout << "Enter your choice: ";
   std::cin >> choice;
   std::cin.ignore();

   switch (choice)
   {
   case 1:
   addResource(resources);
   std::cout << std::endl;
   break;

   case 2:
   viewResources(resources);
   std::cout << std::endl;
   break;

   case 3:
   updateResource(resources);
   std::cout << std::endl;
   break;

   case 4:
   std::cout << "Exiting...";
   break;

   default:
   std::cout << "Invalid choice! Please try again.\n";
   }

   } while (choice != 4);
   return 0;
}

// Implement the rest of the functions here

// Constructor definition
CommunityResource::CommunityResource(std::string n, std::string t, 
   std::string a, std::string c) 
{
   name = n;
   type = t;
   address = a;
   contact = c;
}

/*
* function_identifier: Gets the name of a resource
* parameters: void
* return value: returns a string containing the name of the resource
*/
std::string CommunityResource::getName() const 
{
   return name;
}

/*
* function_identifier: Gets the type of a resource
* parameters: void
* return value: returns a string containing the type of the resource
*/
std::string CommunityResource::getType() const 
{
   return type;
}

/*
* function_identifier: Gets the address of a resource
* parameters: void
* return value: returns a string containing the address of the resource
*/
std::string CommunityResource::getAddress() const 
{
   return address;
}

/*
* function_identifier: Gets the contact of a resource
* parameters: void
* return value: returns a string containing the contact of the resource
*/
std::string CommunityResource::getContact() const 
{
   return contact;
}

/*
* function_identifier: Sets the name of a resource
* parameters: new name of resource
* return value: void
*/
void CommunityResource::setName(std::string n) 
{
   name = n;
}

/*
* function_identifier: Sets the type of a resource
* parameters: new type of resource
* return value: void
*/
void CommunityResource::setType(std::string t) 
{
   type = t;
}

/*
* function_identifier: Sets the address of a resource
* parameters: new address of resource
* return value: void
*/
void CommunityResource::setAddress(std::string a) 
{
   address = a;
}

/*
* function_identifier: Sets the contact of a resource
* parameters: new contact of resource
* return value: void
*/
void CommunityResource::setContact(std::string c) 
{
   contact = c;
}

/*
* function_identifier: Displays details of a resource
* parameters: void
* return value: void
*/
void CommunityResource::displayResource() const 
{
   std::cout << "Name: " << name << std::endl;
   std::cout << "Type: " << type << std::endl;
   std::cout << "Address: " << address << std::endl;
   std::cout << "Contact: " << contact << std::endl;
};

/*
* function_identifier: Creates a resource and adds it to collection
* parameters: resource vector
* return value: void
*/
void addResource(std::vector<CommunityResource>& resources) 
{
   std::string name;
   std::string type;
   std::string address;
   std::string contact;

   std::cout << "Enter the name of the resource: ";
   std::getline(std::cin, name);

   std::cout << "Enter the type of the resource: ";
   std::getline(std::cin, type);

   std::cout << "Enter the address of the resource: ";
   std::getline(std::cin, address);

   std::cout << "Enter the contact information: ";
   std::getline(std::cin, contact);

   if (resourceExists(name, resources))
   {
      std::cout << "\nERROR: Resource already exists." << std::endl;
   }
   else 
   {
      CommunityResource newResource(name, type, address, contact);
      resources.push_back(newResource);
      std::cout << "Resource added successfully!";
   }

   
}

/*
* function_identifier: Loop through all resources and display their 
* details
* parameters: resources vector
* return value: void
*/
void viewResources(const std::vector<CommunityResource>& resources) 
{
   if (resources.size() == 0) 
   {
      std::cout << "No resources available.";
   }

   for (int i = 0; i < resources.size(); i++) 
   {
      resources[i].displayResource();
      std::cout << "-----------------------";
   }
}

/*
* function_identifier: Updates details for any resource
* parameters: resources vector
* return value: void
*/
void updateResource(std::vector<CommunityResource>& resources) 
{
   std::string resourceName;

   std::cout << "Enter the name of the resource you want to update: ";
   std::getline(std::cin, resourceName);

   for (int i = 0; i < resources.size(); i++) 
   {
      if (resources[i].getName() == resourceName) 
      {
         updateDetails(resources[i]);
         std::cout << "resource updated successfully!";
         return;
      }
   }

   std::cout << "Resource not found.";
}


/*
* function_identifier: Update details for a specified resource
* parameters: Specified resource
* return value: void
*/
void updateDetails(CommunityResource& resource) 
{
         std::string newName;
         std::string newType;
         std::string newAddress;
         std::string newContact;

         std::cout << "Enter the new name "
         "(or press Enter to keep current): ";
         std::getline(std::cin, newName);
         if (newName != "") 
         {
            resource.setName(newName);
         }

         std::cout << "Enter the new type "
         "(or press Enter to keep current): ";
         std::getline(std::cin, newType);
         if (newType != "") 
         {
            resource.setType(newType);
         }

         std::cout << "Enter the new address "
            "(or press Enter to keep current): ";
         std::getline(std::cin, newAddress);
         if (newAddress != "") 
         {
            resource.setAddress(newAddress);
         }

         std::cout << "Enter the new contact "
            "(or press Enter to keep current): ";
         std::getline(std::cin, newContact);
         if (newContact != "") 
         {
            resource.setContact(newContact);
         }

}

/*
* function_identifier: Checks if a resource exists based on name
* parameters: Name of new resource and resources vector
* return value: True if already exists, false if not
*/
bool resourceExists(std::string name, 
   std::vector<CommunityResource>& resources)
{
   for (int i = 0; i < resources.size(); i++) 
   {
      if (name == resources[i].getName())
      {
         return true;
      }
   }

   return false;
}
