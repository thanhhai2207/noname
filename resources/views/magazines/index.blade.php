@extends('layouts.master')

@section('content')
    <div class="container">
        <!-- Form tìm kiếm -->
        <form action="{{ route('magazines.index') }}" method="GET">
            <div class="row mb-3">
                <div class="col-md-8">
                    <input type="text" name="search" class="form-control" placeholder="Tìm kiếm tạp trí..." value="{{ request('search') }}">
                </div>
                <div class="col-md-4">
                    <button type="submit" class="btn btn-primary w-100">Tìm kiếm</button>
                </div>
            </div>
        </form>

        <h2>Danh sách tạp trí</h2>
        {{-- <a href="{{ route('magazines.create') }}" class="btn btn-primary mb-3">Thêm tạp trí</a> --}}
        
        <!-- Kiểm tra nếu có kết quả tìm kiếm -->
        @if($magazines->isEmpty())
            <p>Không tìm thấy tạp trí nào.</p>
        @else
            <div class="row">
                @foreach($magazines as $magazine)
                    <div class="col-md-4">
                        <div class="card mb-4 shadow-sm">
                            
                            <div class="card-body">
                                <h5 class="card-title">{{ $magazine->title }}</h5>
                                <p class="card-text"><strong>Ngày phát hành:</strong> {{ $magazine->release_date }}</p>
                                <p class="card-text"><strong>Đề tài:</strong> {{ $magazine->topic }}</p>
                                <p class="card-text"><strong>Nhà xuất bản:</strong> {{ $magazine->publisher->name }}</p>
                                <a href="{{ route('magazines.show', $magazine->id) }}" class="btn btn-primary">Xem chi tiết</a>
                            </div>
                        </div>
                    </div>
                @endforeach
            </div>
        @endif
    </div>
@endsection
