# 面向对象购物系统项目大纲

#### 1. **Product 类 (基础类)**
- **属性:** `int productId`, `String name`, `double price`。
- **方法:** 构造函数，获取和设置方法。
- **数据结构/算法:** N/A。

#### 2. **SpecialProduct 类 (继承自 Product)**
- **属性:** `String specialFeature`。
- **方法:** 为特殊特性的构造函数，获取和设置方法。
- **数据结构/算法:** 继承自 Product，展示 OOP 继承。

#### 3. **Inventory 类 (使用双向链表)**
- **属性:** `DoublyLinkedList<Product> products`。
- **方法:** `addProduct(Product product)`, `removeProduct(int productId)`, `Product getProduct(int productId)`, `List<Product> searchProducts(String query)`, `void sortProducts()`。
- **数据结构/算法:** 使用双向链表存储产品，方便高效地插入和删除。实现产品管理的搜索和排序算法。

#### 4. **CartItem 类**
- **属性:** `Product product`, `int quantity`。
- **方法:** 构造函数，获取和设置方法，`double getTotalPrice()`。
- **数据结构/算法:** N/A。

#### 5. **Cart 类 (使用双向链表)**
- **属性:** `DoublyLinkedList<CartItem> items`。
- **方法:** `void addItem(CartItem item)`, `void removeItem(int productId)`, `double calculateTotal()`, `void sortCartItems()`。
- **数据结构/算法:** 使用双向链表管理 CartItem 对象。为整理购物车项目提供排序方法。

#### 6. **User 类 (使用 HashMap)**
- **属性:** `int userId`, `String username`, `String passwordHash`, `Cart cart`。
- **方法:** 构造函数，获取和设置方法，`void login(String password)`。
- **数据结构/算法:** 使用 HashMap 管理用户信息和认证。

#### 7. **Store 类**
- **属性:** `Inventory inventory`, `HashMap<Integer, User> users`。
- **方法:** `registerUser(User user)`, `User getUser(int userId)`, `void checkout(User user)`。
- **数据结构/算法:** 使用 HashMap 管理用户并链接到各自的购物车。

### 关键特性

- **双向链表:** 在 Inventory 和 Cart 类中用于高效地操纵产品和购物车项目列表。
- **HashMap:** 在 User 类中用于高效数据检索，在 Store 类中管理用户。
- **继承:** 在 SpecialProduct 类继承 Product 类中展示。
- **排序和搜索:** 在 Inventory 类中集成用于产品管理，在 Cart 类中用于组织购物车项目。

遵循此大纲，您的面向对象购物系统将有效地使用数据结构和算法组合来管理产品、用户和购物车项目，同时展示继承等关键面向对象编程原则。
