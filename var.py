import tabula

def read_pdf_page(pdf_path, page_number):
    try:
        df = tabula.read_pdf(pdf_path, page_number)