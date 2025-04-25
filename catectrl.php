<?php
namespace App\Controllers;

use App\Models\Category;

class CategoryController extends Controller {
    // Hiển thị danh sách danh mục
    public function index() {
        $modelCategory = new Category();
        $title = 'Danh sách danh mục';
        $dataCate = $modelCategory->getAllCategories();
        return $this->views('category.list', compact('title', 'dataCate'));
    }

    // Xóa danh mục
}
