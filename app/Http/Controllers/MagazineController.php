<?php

namespace App\Http\Controllers;

use App\Models\Magazine;
use App\Models\Publisher;
use Illuminate\Http\Request;

class MagazineController extends Controller
{
    public function index(Request $request)
    {
        // Kiểm tra xem có từ khóa tìm kiếm hay không
        $search = $request->input('search');

        // Nếu có từ khóa tìm kiếm, sử dụng LIKE để tìm tạp trí theo tiêu đề
        if ($search) {
            $magazines = Magazine::where('title', 'LIKE', '%' . $search . '%')
                ->orderBy('created_at', 'desc')
                ->get();
        } else {
            // Nếu không có tìm kiếm, lấy tất cả tạp trí
            $magazines = Magazine::orderBy('created_at', 'desc')->get();
        }

        // Trả về view với các tạp trí và từ khóa tìm kiếm
        return view('magazines.index', compact('magazines', 'search'));
    }
    public function show($id)
    {
        // Lấy tạp chí theo ID, nếu không tìm thấy sẽ trả về lỗi 404
        $magazine = Magazine::with('publisher')->findOrFail($id);
    
        // Lấy 5 tạp trí cùng nhà xuất bản, loại trừ tạp trí hiện tại
        $relatedMagazines = Magazine::where('publisher_id', $magazine->publisher_id)
    ->where('id', '!=', $magazine->id)
    ->orderByRaw('STR_TO_DATE(release_date, "%Y-%m-%d") DESC') // ép kiểu nếu DB bị sai
    ->take(5)
    ->get();

    
    
        // Trả về view chi tiết tạp chí với dữ liệu
        return view('magazines.show', compact('magazine', 'relatedMagazines'));
    }
   public function create()
    {
        return view('magazines.create');
    }

    // Phương thức lưu tạp chí mới
    public function store(Request $request)
    {
        // Xử lý dữ liệu form và lưu vào cơ sở dữ liệu
        // (Giả sử bạn đã có model Magazine)
        $request->validate([
            'title' => 'required|string|max:255',
            'content' => 'required|string',
        ]);

        // Lưu tạp chí vào database
        \App\Models\Magazine::create([
            'title' => $request->title,
            'content' => $request->content,
        ]);

        return redirect()->route('magazines.create')->with('success', 'Tạp chí đã được tạo!');
    }
    
}
