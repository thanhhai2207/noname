<?php
namespace App\Models;

use App\Models\Model;

class Category extends Model {
    protected $table = 'categories';
    private $connection;

    public function __construct() {
        $this->connection = new Model();
    }

    // Lấy tất cả danh mục
    public function getAllCategories() {
        $sql = "SELECT * FROM {$this->table}";
        $this->connection->setSQL($sql);
        return $this->connection->all();
    }

    // Lấy danh mục theo ID
    public function getCategoryById($id) {
        $sql = "SELECT * FROM {$this->table} WHERE id = ?";
        $this->connection->setSQL($sql);
        return $this->connection->first([$id]);
    }

    // Thêm danh mục
    public function addCategory($name) {
        $sql = "INSERT INTO {$this->table} (name) VALUES (?)";
        $this->connection->setSQL($sql);
        return $this->connection->execute([$name]);
    }

    // Cập nhật danh mục

}
?>